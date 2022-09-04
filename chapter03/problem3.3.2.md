# Problem 3.3.2

For $\mathbf{x} = \begin{pmatrix}x_1 \\ x_2 \\ \vdots \\ x_n\end{pmatrix}$, and
for constant $\xi_i$, verify that

$$f\left(\mathbf{x}\right)=\xi_1 x_1 + \xi_2 x_2 + \dotsb + \xi_n x_n$$

is a linear function.

$$
\begin{split}
f\left(\alpha\mathbf{x}+\mathbf{y}\right) &
  = \xi_1\left(\alpha x_1 + y_1\right) + \xi_2\left(\alpha x_2 + y_2\right)
    + \dotsb + \xi_1\left(\alpha x_1 + y_1\right) \\
& = \alpha\left(\xi_1 x_1 + \xi_2 x_2 + \dotsb + \xi_n x_n\right)
  + \left(\xi_1 y_1 + \xi_2 y_2 + \dotsb + \xi_n y_n\right) \\
& = \alpha f\left(\mathbf{x}\right) + f\left(\mathbf{y}\right)
\end{split}
$$
