# Problem 3.6.3

$$
\mathbf{A} =
\begin{pmatrix}
  1 & 0 & 0 & 1/3 & 1/3 & 1/3 \\
  0 & 1 & 0 & 1/3 & 1/3 & 1/3 \\
  0 & 0 & 1 & 1/3 & 1/3 & 1/3 \\
  0 & 0 & 0 & 1/3 & 1/3 & 1/3 \\
  0 & 0 & 0 & 1/3 & 1/3 & 1/3 \\
  0 & 0 & 0 & 1/3 & 1/3 & 1/3 \\
\end{pmatrix}
$$

Determine $\mathbf{A}^{300}$. Let

$$
\mathbf{A} =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C}\\
  \mathbf{\large{0}} & \mathbf{C}
\end{pmatrix}
$$

where $\mathbf{C} =
\dfrac{1}{3}\begin{pmatrix}
  1 & 1 & 1 \\
  1 & 1 & 1 \\
  1 & 1 & 1 \\
\end{pmatrix} $.

$$
\begin{align*}
\mathbf{A}^2 & =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C}\\
  \mathbf{0} & \mathbf{C}
\end{pmatrix}^2 \\
& = \begin{pmatrix}
  \mathbf{I}^2 + \mathbf{C0} & \mathbf{IC} + \mathbf{C}^2\\
  \mathbf{0I} + \mathbf{C0} & \mathbf{0C} + \mathbf{C}^2
\end{pmatrix} \\
& =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C} + \mathbf{C}^2 \\
  \mathbf{0} & \mathbf{C}^2
\end{pmatrix}
\end{align*}
$$

$$
\begin{align*}
\mathbf{A}^3 & =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C}\\
  \mathbf{0} & \mathbf{C}
\end{pmatrix}^3 \\
& =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C} + \mathbf{C}^2 \\
  \mathbf{0} & \mathbf{C}^2
\end{pmatrix}
\begin{pmatrix}
  \mathbf{I} & \mathbf{C}\\
  \mathbf{\large{0}} & \mathbf{C}
\end{pmatrix} \\
& =
\begin{pmatrix}
  \mathbf{I}^2 + \left(\mathbf{C} + \mathbf{C}^2\right)\mathbf{0}
    & \mathbf{IC} + \left(\mathbf{C} + \mathbf{C}^2\right)\mathbf{C} \\
  \mathbf{0I} + \mathbf{C}^2\mathbf{0} & \mathbf{0C} + \mathbf{C}^3
\end{pmatrix} \\
& =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C} + \mathbf{C}^2 + \mathbf{C}^3 \\
  \mathbf{0} & \mathbf{C}^3
\end{pmatrix}
\end{align*}
$$

$$
\begin{align*}
\mathbf{A}^4 & =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C}\\
  \mathbf{0} & \mathbf{C}
\end{pmatrix}^4 \\
& =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C} + \mathbf{C}^2 + \mathbf{C}^3 \\
  \mathbf{0} & \mathbf{C}^3
\end{pmatrix}
\begin{pmatrix}
  \mathbf{I} & \mathbf{C}\\
  \mathbf{\large{0}} & \mathbf{C}
\end{pmatrix} \\
& =
\begin{pmatrix}
  \mathbf{I}^2 + \left(\mathbf{C} + \mathbf{C}^2 + \mathbf{C}^3\right)
    \mathbf{0}
    & \mathbf{IC} + \left(\mathbf{C} + \mathbf{C}^2 + \mathbf{C}^3\right)
      \mathbf{C} \\
  \mathbf{0I} + \mathbf{C}^3\mathbf{0} & \mathbf{0C} + \mathbf{C}^4
\end{pmatrix} \\
& =
\begin{pmatrix}
  \mathbf{I} & \mathbf{C} + \mathbf{C}^2 + \mathbf{C}^3 + \mathbf{C}^4\\
  \mathbf{0} & \mathbf{C}^4
\end{pmatrix}
\end{align*}
$$

$$
\mathbf{A}^n =
\begin{pmatrix}
  \mathbf{I} & \sum_{i=1}^n\mathbf{C}^n \\
  \mathbf{0} & \mathbf{C}^n
\end{pmatrix} =
\begin{pmatrix}
  \mathbf{I} & n\mathbf{C} \\
  \mathbf{0} & \mathbf{C}
\end{pmatrix}
$$

$$
\begin{align*}
\mathbf{A}^{300} & =
\begin{pmatrix}
  \mathbf{I} & 300\mathbf{C} \\
  \mathbf{0} & \mathbf{C}
\end{pmatrix} \\
& = \begin{pmatrix}
  1 & 0 & 0 & 100 & 100 & 100 \\
  0 & 1 & 0 & 100 & 100 & 100 \\
  0 & 0 & 1 & 100 & 100 & 100 \\
  0 & 0 & 0 & 1/3 & 1/3 & 1/3 \\
  0 & 0 & 0 & 1/3 & 1/3 & 1/3 \\
  0 & 0 & 0 & 1/3 & 1/3 & 1/3
\end{pmatrix}
\end{align*}
$$
