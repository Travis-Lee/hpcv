#ifndef VISION_NORMALIZE_H
#define VISION_NORMALIZE_H

void hwc_neon_mean_scale(const float* din,
                     float* dout,
                     int size,
                     float* mean,
                     float* scale);

void chw_neon_mean_scale(const float* din,
                     float* dout,
                     int size,
                     float* mean,
                     float* scale);
#endif
