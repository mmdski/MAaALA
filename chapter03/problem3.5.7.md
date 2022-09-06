# Problem 3.5.7

$\mathbf{C}_{m\times 1}$ and $\mathbf{R}_{1\times n}$,
$\mathbf{P}_{m\times n} = \mathbf{CR}$

$$
\begin{split}
\mathbf{A}_{m\times p}\mathbf{B}_{p \times n} & =

\begin{pmatrix}
  a_{11}b_{11} + \dots + a_{1p}b_{p1} &
    \dots &
    a_{11}b_{1n} + \dots + a_{1p}b_{pn} \\
  \vdots & \ddots & \vdots \\
  a_{m1}b_{11} + \dots + a_{mp}b_{p1} &
    \dots &
    a_{m1}b_{1n} + \dots + a_{mp}b_{pn} \\
\end{pmatrix} \\

& = \begin{pmatrix}
  a_{11}b_{11}  & \dots & a_{11}b_{1n} \\
  \vdots & \ddots & \vdots \\
  a_{m1}b_{11} & \dots & a_{m1}b_{1n}
\end{pmatrix} + \dots +
\begin{pmatrix}
  a_{1p}b_{p1} & \dots & a_{1p}b_{pn} \\
  \vdots & \ddots & \vdots \\
  a_{mp}b_{p1} & \dots & a_{mp}b_{pn}
\end{pmatrix} \\

& = \mathbf{A}_{*1}\mathbf{B}_{1*} + \dots + \mathbf{A}_{*p}\mathbf{B}_{p*}
\end{split}
$$

$$
\mathbf{A}_{m\times p}\mathbf{B}_{p \times n} =
  \sum^{p}_{k=1}\mathbf{A}_{*k}\mathbf{B}_{k*}
$$
