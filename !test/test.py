import numpy as np

iterations = 10**8
mat = np.random.rand(iterations, 2)

mat.sort()
# swap_mask = (mat[:, 0] > mat[:, 1])
# mat[swap_mask] = mat[swap_mask][:, ::-1]

bools = (mat[:, 0] < 0.5) & (mat[:, 1] < 0.5) & (mat[:, 1] - mat[:, 0] < 0.5)
ret = np.mean(bools)

# print(mat)
# print(bools)
print(ret)
