# Problem 3.6.2

$$
\mathbf{L} =
\begin{pmatrix}
  \mathbf{I}-\mathbf{BA} & \mathbf{B} \\
  2\mathbf{A}-\mathbf{ABA} & \mathbf{AB}-\mathbf{I}
\end{pmatrix}
$$

$$
\begin{align*}
\mathbf{L}^2 &
= \begin{pmatrix}
  \mathbf{I}-\mathbf{BA} & \mathbf{B} \\
  2\mathbf{A}-\mathbf{ABA} & \mathbf{AB}-\mathbf{I}
\end{pmatrix}^2 \\
& = \begin{pmatrix}
  \mathbf{I}-\mathbf{BA} & \mathbf{B} \\
  2\mathbf{A}-\mathbf{ABA} & \mathbf{AB}-\mathbf{I}
\end{pmatrix} \begin{pmatrix}
  \mathbf{I}-\mathbf{BA} & \mathbf{B} \\
  2\mathbf{A}-\mathbf{ABA} & \mathbf{AB}-\mathbf{I}
\end{pmatrix}\\
& = \begin{pmatrix}
  \left(\mathbf{I}-\mathbf{BA}\right)^2
    + \mathbf{B}\left(2\mathbf{A}-\mathbf{ABA}\right) &
  \left(\mathbf{I}-\mathbf{BA}\right)\mathbf{B}
    + \mathbf{B}\left(\mathbf{AB}-\mathbf{I}\right) \\
  \left(2\mathbf{A}-\mathbf{ABA}\right)\left(\mathbf{I}-\mathbf{BA}\right)
    + \left(\mathbf{AB}-\mathbf{I}\right)
      \left(2\mathbf{A}-\mathbf{ABA}\right) &
  \left(2\mathbf{A}-\mathbf{ABA}\right)\mathbf{B} +
    \left(\mathbf{AB}-\mathbf{I}\right)^2
\end{pmatrix}
\end{align*}
$$

$\left[\mathbf{L}^2\right]_{1,1}$:

$$
\begin{align*}
\left(\mathbf{I}-\mathbf{BA}\right)^2
  + \mathbf{B}\left(2\mathbf{A}-\mathbf{ABA}\right) & =
  \mathbf{I}^2-2\mathbf{BA}+\mathbf{BA}^2+2\mathbf{BA}-\mathbf{BA}^2 \\
  & = \mathbf{I}^2 - \cancel{2\mathbf{BA}} + \cancel{\mathbf{BA}^2}
    + \cancel{2\mathbf{BA}} - \cancel{\mathbf{BA}^2} \\
  & = \mathbf{I}
\end{align*}
$$

$\left[\mathbf{L}^2\right]_{1,2}$:

$$
\begin{align*}
\left(\mathbf{I}-\mathbf{BA}\right)\mathbf{B}
    + \mathbf{B}\left(\mathbf{AB}-\mathbf{I}\right) & =
  \mathbf{B} - \mathbf{BAB} + \mathbf{BAB} - \mathbf{B} \\
  & = \cancel{\mathbf{B}} - \cancel{\mathbf{BAB}}
    + \cancel{\mathbf{BAB}} - \cancel{\mathbf{B}} \\
  & = \mathbf{0}
\end{align*}
$$

$\left[\mathbf{L}^2\right]_{2,1}$:

$$
\begin{align*}
& \left(2\mathbf{A}-\mathbf{ABA}\right)\left(\mathbf{I}-\mathbf{BA}\right)
  + \left(\mathbf{AB}-\mathbf{I}\right)
    \left(2\mathbf{A}-\mathbf{ABA}\right) \\
& \quad = 2\mathbf{A} - 2\mathbf{ABA} - \mathbf{ABA} + \mathbf{ABABA}
  + 2\mathbf{ABA} - \mathbf{ABABA} - 2\mathbf{A} + \mathbf{ABA} \\
& \quad = \cancel{2\mathbf{A}}
  - \cancel{2\mathbf{ABA}}
  - \cancel{\mathbf{ABA}}
  + \cancel{\mathbf{ABABA}}
  + \cancel{2\mathbf{ABA}}
  - \cancel{\mathbf{ABABA}}
  - \cancel{2\mathbf{A}}
  + \cancel{\mathbf{ABA}} \\
& \quad = \mathbf{0}
\end{align*}
$$

$\left[\mathbf{L}^2\right]_{2,2}$:

$$
\begin{align*}
\left(2\mathbf{A}-\mathbf{ABA}\right)\mathbf{B} & +
  \left(\mathbf{AB}-\mathbf{I}\right)^2 \\
  & = 2\mathbf{AB} - \mathbf{ABAB} + \mathbf{ABAB}
    - 2\mathbf{AB} + \mathbf{I}^2 \\
  & = \cancel{2\mathbf{AB}}
    - \cancel{\mathbf{ABAB}}
    + \cancel{\mathbf{ABAB}}
    - \cancel{2\mathbf{AB}}
    + \mathbf{I}^2 \\
  & = \mathbf{I}
\end{align*}
$$

$$
\mathbf{L}^2 =
\left(
  \begin{array}{cc}
    \mathbf{I} & \mathbf{0} \\
    \mathbf{0} & \mathbf{I}
  \end{array}
\right) = \mathbf{I}
$$
