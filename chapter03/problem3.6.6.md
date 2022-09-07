# Problem 3.6.6

Prove $\left(\mathbf{A} + \mathbf{B}\right)\mathbf{C} =
  \mathbf{AC} + \mathbf{AB}$

$$
\begin{align*}
\left[\left(\mathbf{A} + \mathbf{B}\right)\mathbf{C}\right]_{i,j}
  & = \left(\mathbf{A}+\mathbf{B}\right)_{i*}\mathbf{C}_{*j}
  = \sum_k\left[\mathbf{A}+\mathbf{B}\right]_{i,k}
    \left[\mathbf{C}\right]_{k,j} \\
  & = \sum_k\left(\left[\mathbf{A}\right]_{i,k}
      +\left[\mathbf{B}\right]_{i,k}\right)
    \left[\mathbf{C}\right]_{k,j} \\
  & = \sum_k \left(
    \left[\mathbf{A}\right]_{i,k}\left[\mathbf{C}\right]_{k,j} +
    \left[\mathbf{B}\right]_{i,k}\left[\mathbf{C}\right]_{k,j}
  \right) \\
  & = \sum_k \left[\mathbf{A}\right]_{i,k}\left[\mathbf{C}\right]_{k,j} +
    \sum_k \left[\mathbf{B}\right]_{i,k}\left[\mathbf{C}\right]_{k,j} \\
  & = \mathbf{A}_{i*}\mathbf{C}_{*j} + \mathbf{B}_{i*}\mathbf{C}_{*j} \\
  & = \left[\mathbf{AC}\right]_{i,j} + \left[\mathbf{BC}\right]_{i,j} \\
  & = \left[\mathbf{AC} + \mathbf{BC}\right]_{i,j}
\end{align*}
$$
