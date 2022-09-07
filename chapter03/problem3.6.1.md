# Problem 3.6.1

$\mathbf{A} =
\left(
  \begin{array}{c|cc|ccc}
    1 & 0 & 0 & 3 & 3 & 3 \\
    1 & 0 & 0 & 3 & 3 & 3 \\
    \hline
    1 & 2 & 2 & 0 & 0 & 0
  \end{array}
\right)\quad
$ and
$\quad\mathbf{B} =
\left(
  \begin{array}{cc}
    -1 & -1 \\
    \hline
    0 & 0 \\
    0 & 0 \\
    \hline
    -1 & -2 \\
    -1 & -2 \\
    -1 & -2
  \end{array}
\right)
$

$$
\begin{align*}
\mathbf{AB} &=
  \left(
    \begin{array}{ccc}
      \mathbf{A}_{1,1} & \mathbf{A}_{1,2} & \mathbf{A}_{1,3} \\
      \mathbf{A}_{2,1} & \mathbf{A}_{2,2} & \mathbf{A}_{2,3}
    \end{array}
  \right)
  \left(
    \begin{array}{c}
      \mathbf{B}_1 \\
      \mathbf{B}_2 \\
      \mathbf{B}_3
    \end{array}
  \right) \\
&=\left(
    \begin{array}{c}
      \mathbf{A}_{1,1}\mathbf{B}_1 + \mathbf{A}_{1,2}\mathbf{B}_2
        + \mathbf{A}_{1,3}\mathbf{B}_3 \\
      \mathbf{A}_{2,1}\mathbf{B}_1 + \mathbf{A}_{2,2}\mathbf{B}_2
        + \mathbf{A}_{2,3}\mathbf{B}_3
    \end{array}
  \right)
\end{align*}
$$

$$
\mathbf{A}_{1,1}\mathbf{B}_1 =
  \left(
    \begin{array}{cc}
      -1 & -1 \\
      -1 & -1
    \end{array}
  \right)
$$

$$
\mathbf{A}_{1,2}\mathbf{B}_2 =
  \left(
    \begin{array}{cc}
      0 & 0 \\
      0 & 0
    \end{array}
  \right)
$$

$$
\mathbf{A}_{1,3}\mathbf{B}_3 =
  \left(
    \begin{array}{cc}
      -9 & -18 \\
      -9 & -18
    \end{array}
  \right)
$$

$$
\mathbf{A}_{2,1}\mathbf{B}_1=
  \left(
    \begin{array}{cc}
      -1 & -1
    \end{array}
  \right)
$$

$$
\mathbf{A}_{2,2}\mathbf{B}_2=
  \left(
    \begin{array}{cc}
      0 & 0
    \end{array}
  \right)
$$

$$
\mathbf{A}_{2,3}\mathbf{B}_3=
  \left(
    \begin{array}{cc}
      0 & 0
    \end{array}
  \right)
$$

$$
\mathbf{AB} = \left(
    \begin{array}{cc}
      -10 & -19 \\
      -10 & -19 \\
      \hline
      -1 & -1
    \end{array}
  \right)
$$
