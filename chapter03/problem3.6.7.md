# Problem 3.6.7

$$
\mathbf{AX} - \mathbf{XA} = \mathbf{I}
$$

$$
\left[\mathbf{AX} - \mathbf{XA}\right]_{i,j}
  = \sum^n_{k=1}\left(a_{i,k}x_{k,j} - x_{i,k}a_{k,j}\right)
  = \sum^n_{k=1}a_{i,k}x_{k,j} - \sum^n_{k=1}x_{i,k}a_{k,j}
$$

$$
\begin{align*}
trace\left(\mathbf{AX} - \mathbf{XA}\right) & =
  \sum_{i=1}^n\left[\mathbf{AX} - \mathbf{XA}\right]_{i,i} \\
  & = \sum^n_{k=1}a_{i,k}x_{k,i} - \sum^n_{k=1}x_{i,k}a_{k,i} \\
  & = trace\left(\mathbf{AX}\right) - trace\left(\mathbf{XA}\right)
\end{align*}
$$

Since $trace\left(\mathbf{AX}\right) = trace\left(\mathbf{XA}\right)$,

$$
trace\left(\mathbf{AX}-\mathbf{XA}\right) = 0
$$

However, $trace\left(\mathbf{I}\right) = n$.  Since
$trace\left(\mathbf{AX}-\mathbf{XA}\right) = 0$ is universally true,
$trace\left(\mathbf{AX}-\mathbf{XA}\right) \ne n$ and so it is impossible to
find $\mathbf{X}$ such that $\mathbf{AX} - \mathbf{XA} = \mathbf{I}.$
