import numpy as np
import scipy.stats as stats
import statsmodels.api as sm


def calculate_test_statistic(ts):
    zscores = abs(stats.zscore(ts, ddof=1))
    max_idx = np.argmax(zscores)
    return max_idx, zscores[max_idx]

def calculate_critical_value(ts, alpha):
    
    size   = len(ts)
    t_dist = stats.t.ppf(1 - alpha / (2 * size), size - 2)
    
    numerator   = (size - 1) * t_dist
    denominator = np.sqrt(size ** 2 - size * 2 + size * t_dist ** 2)

    return numerator / denominator


def seasonal_esd(ts, seasonality=None, hybrid=False, max_anomalies=10, alpha=0.05):
    ts = np.array(ts)
    seasonal = seasonality or int(0.2 * len(ts)) # Seasonality is 20% of the ts if not given.
    decomp   = sm.tsa.seasonal_decompose(ts, freq=seasonal)
    if hybrid:
        mad      = np.median(np.abs(ts - np.median(ts)))
        residual = ts - decomp.seasonal - mad
    else:
        residual = ts - decomp.seasonal - np.median(ts)
    outliers = esd(residual, max_anomalies=max_anomalies, alpha=alpha)
    return outliers

def esd(timeseries, max_anomalies=10, alpha=0.05):
    ts = np.copy(np.array(timeseries))
    test_statistics = []
    total_anomalies = -1
    for curr in range(max_anomalies):
        test_idx, test_val = calculate_test_statistic(ts)
        critical_value     = calculate_critical_value(ts, alpha)
        if test_val > critical_value:
            total_anomalies = curr
        test_statistics.append(test_idx)
        ts = np.delete(ts, test_idx)
    anomalous_indices = test_statistics[:total_anomalies + 1]
    return anomalous_indices
