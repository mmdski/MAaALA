# Problem 3.6.5

$\mathbf{A}$ and $\mathbf{B}$ are symmetric matrices that commute. Prove that
$\mathbf{AB}$ is also symmetric.

$$
\left[\mathbf{AB}\right]_{i,j} = \mathbf{A}_{i*}\mathbf{B}_{*j}
  = \sum_{k = 1}^n a_{i,k}b_{k,j}
$$

$$
\left[\mathbf{BA}\right]_{i,j} = \mathbf{B}_{i*}\mathbf{A}_{*j}
  = \sum_{k = 1}^n b_{i,k}a_{k,j}
$$

$$
\begin{align*}
\mathbf{AB} = \mathbf{BA} \rightarrow
 \left[\mathbf{AB}\right]_{i,j} &= \left[\mathbf{BA}\right]_{i,j} \\
 \sum_{k = 1}^n a_{i,k}b_{k,j}  &= \sum_{k = 1}^n b_{i,k}a_{k,j}
\end{align*}
$$

$$
\sum_{k = 1}^n b_{i,k}a_{k,j} = \sum_{k = 1}^n a_{k,j}b_{i,k}
$$

Since $\mathbf{A}$ and $\mathbf{B}$ are symmetric, $a_{k,j} = a_{j,k}$ and
  $b_{i,k} = b_{k,i}$.

$$
\sum_{k = 1}^n a_{k,j}b_{i,k} = \sum_{k = 1}^n a_{j,k}b_{k,i}
$$

Therefore,

$$
\sum_{k = 1}^n a_{i,k}b_{k,j} = \sum_{k = 1}^n a_{j,k}b_{k,i}
\rightarrow \left[\mathbf{AB}\right]_{i,j} = \left[\mathbf{AB}\right]_{j,i}
$$

and $\mathbf{AB}$ is symmetric.

***
A more direct proof

$$
\left(\mathbf{AB}\right)^T = \mathbf{B}^T\mathbf{A}^T =
  \mathbf{BA} = \mathbf{AB}
$$
