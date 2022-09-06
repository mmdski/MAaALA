# Problem 3.5.8

$\mathbf{U} = \left[u_{ij}\right]$ is upper triangular, such that
$u_{ij} = 0$ for $i > j$.

$\mathbf{A} = \begin{pmatrix}
a_{1,1} & a_{1,2} & a_{1,3} & \dots  & a_{1,n} \\
        & a_{2,2} & a_{2,3} & \dots  & a_{2,n} \\
        &         & \ddots  & \ddots & \vdots  \\
        &         &         & \ddots & a_{n-1,n}  \\
  0     &         &         &        & a_{n,n}
\end{pmatrix}$

$\mathbf{B} = \begin{pmatrix}
b_{1,1} & b_{1,2} & b_{1,3} & \dots  & b_{1,n} \\
        & b_{2,2} & b_{2,3} & \dots  & b_{2,n} \\
        &         & \ddots  & \ddots & \vdots  \\
        &         &         & \ddots & b_{n-1,n}  \\
  0     &         &         &        & b_{n,n}
\end{pmatrix}$

***

(a) Show that $\mathbf{AB}$ is upper triangular.

$$
\begin{split}
\left[\mathbf{A}\mathbf{B}\right]_{i,j} =
\mathbf{A}_{i*}\mathbf{B}_{*j} & = \sum_{k=1}^{n}a_{i,k}b_{k,j} \\
& = a_{i,1}b_{1,j} + a_{i,2}b_{2,j} + \cdots
  + a_{i,j}b_{i,j} + \cdots + a_{i,n-1}b_{n-1,j} + a_{i,n}b_{n,j}
\end{split}
$$

- $a_{i,k} = 0$ for $i > k$
- $b_{k,j} = 0$ for $k > j$

For $i > j$

$$
\begin{split}
\sum_{k=1}^{n}a_{i,k}b_{k,j} & =
  0\left(b_{1,j}\right) + 0\left(b_{2,j}\right) + \cdots
  + 0\left(0\right) + \cdots
  + \left(a_{i,n-1}\right)0 + \left(a_{i,n}\right)0 \\
  & = 0
\end{split}
$$

(b) What are the diagonal entries of $\mathbf{AB}$?

$$
\begin{split}
\mathbf{A}_{i*}\mathbf{B}_{*j}\rvert_{i=j} & = \sum_{k=1}^{n}a_{i,k}b_{k,j} \\
& = 0\left(b_{1,j}\right) + 0\left(b_{2,j}\right) + \cdots
  + a_{i,j}b_{i,j} + \cdots
  + \left(a_{i,n-1}\right)0 + \left(a_{i,n}\right)0 \\
& = a_{i,j}b_{i,j}
\end{split}
$$
