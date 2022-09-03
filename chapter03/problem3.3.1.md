# Problem 3.3.1

Each of the following is a function from $\mathfrak{R}^2$ into $\mathfrak{R}^2$.
Determine which are linear functions.

***

(a) $f \begin{pmatrix}x\\y\end{pmatrix} = \begin{pmatrix}x\\1+y\end{pmatrix}$

$$
\begin{split}
f \begin{pmatrix}\alpha x+x^{\prime}\\\alpha y+y^{\prime}\end{pmatrix}& =
\begin{pmatrix}\alpha x+x^{\prime} \\ 1 + \alpha y + y^{\prime}\end{pmatrix} \\
& = \begin{pmatrix}0 \\ 1\end{pmatrix}
  + \begin{pmatrix}\alpha x \\ \alpha y \end{pmatrix}
  + \begin{pmatrix} x^{\prime} \\ y^{\prime} \end{pmatrix} \\
& = \begin{pmatrix}0 \\ 1\end{pmatrix}
  + \alpha\begin{pmatrix}x \\ y \end{pmatrix}
  + \begin{pmatrix} x^{\prime} \\ y^{\prime} \end{pmatrix} \\
& \ne \alpha f\begin{pmatrix}x \\ y\end{pmatrix}
  + f\begin{pmatrix}x^{\prime} \\ y^{\prime}\end{pmatrix}
\end{split}
$$

(a) is not a linear function.

***

(b) $f\begin{pmatrix}x \\ y\end{pmatrix} = \begin{pmatrix} y \\ x\end{pmatrix}$

$$
\begin{split}
f\begin{pmatrix}\alpha x + x^{\prime} \\ \alpha y + y^{\prime}\end{pmatrix}&
= \begin{pmatrix}\alpha y + y^{\prime} \\ \alpha x + x^{\prime}\end{pmatrix} \\
& = \begin{pmatrix}\alpha y \\ \alpha x\end{pmatrix}
  + \begin{pmatrix}y^{\prime} \\ x^{\prime}\end{pmatrix} \\
& = \alpha\begin{pmatrix}y \\ x\end{pmatrix}
  + \begin{pmatrix}y^{\prime} \\ x^{\prime}\end{pmatrix} \\
& = \alpha f\begin{pmatrix}x \\ y\end{pmatrix}
  + f\begin{pmatrix}x^{\prime} \\ y^{\prime}\end{pmatrix}
\end{split}
$$

(b) is a linear function.

***

(c) $f\begin{pmatrix}x \\ y\end{pmatrix}
  = \begin{pmatrix} 0 \\ xy \end{pmatrix}$

$$
\begin{split}
f\begin{pmatrix}\alpha x+x^{\prime}\\\alpha y+y^{\prime}\end{pmatrix}&
= \begin{pmatrix} 0 \\
    \left(\alpha x+x^{\prime}\right) \left(\alpha y+y^{\prime}\right)
    \end{pmatrix} \\
& = \begin{pmatrix} 0 \\
  \alpha^2xy + \alpha x y^{\prime}
    + \alpha x^{\prime} y + x^{\prime}y^{\prime}
  \end{pmatrix} \\
& \ne \alpha f\begin{pmatrix}x \\ y\end{pmatrix}
  + f\begin{pmatrix}x^{\prime} \\ y^{\prime}\end{pmatrix}
\end{split}
$$

(c) is not a linear function.

***

(d) $f\begin{pmatrix}x \\ y\end{pmatrix}
  = \begin{pmatrix}x^2 \\ y^2\end{pmatrix}$

$$
\begin{split}
f\begin{pmatrix}\alpha x + x^{\prime} \\ \alpha y + y^{\prime}\end{pmatrix} &
= \begin{pmatrix}
    \left(\alpha x + x^{\prime}\right)^2 \\
    \left(\alpha y + y^{\prime}\right)^2
  \end{pmatrix} \\
& = \begin{pmatrix}
    \alpha^2 x^2 + 2\alpha x x^{\prime} + \left(x^{\prime}\right)^2 \\
    \alpha^2 y^2 + 2\alpha y y^{\prime} + \left(y^{\prime}\right)^2
  \end{pmatrix} \\
& \ne \alpha f\begin{pmatrix}x \\ y\end{pmatrix}
  + f\begin{pmatrix}x^{\prime} \\ y^{\prime}\end{pmatrix}
\end{split}
$$

(d) is not a linear function.

***

(e) $f\begin{pmatrix}x \\ y\end{pmatrix} =
  \begin{pmatrix}x \\ \sin y\end{pmatrix}$

$$
\begin{split}
f\begin{pmatrix}\alpha x + x^{\prime} \\ \alpha y + y^{\prime}\end{pmatrix} &
  = \begin{pmatrix} \alpha x + x^{\prime} \\
    \sin\left(\alpha y + y^{\prime}\right)\end{pmatrix} \\
& \ne \alpha f\begin{pmatrix}x \\ y\end{pmatrix}
    + f\begin{pmatrix}x^{\prime} \\ y^{\prime}\end{pmatrix}
\end{split}
$$

(e) is not a linear function.

***

(f) $f\begin{pmatrix}x \\ y\end{pmatrix} =
  \begin{pmatrix}x + y \\ x - y\end{pmatrix}$

$$
\begin{split}
f\begin{pmatrix} \alpha x + x^{\prime} \\ \alpha y + y^{\prime}\end{pmatrix} &
  = \begin{pmatrix}
    \left(\alpha x + x^{\prime}\right) + \left(\alpha y + y^{\prime}\right) \\
    \left(\alpha x + x^{\prime}\right) - \left(\alpha y + y^{\prime}\right) \\
  \end{pmatrix} \\
& = \begin{pmatrix}
    \alpha x + \alpha y + x^{\prime} + y^{\prime}\\
    \alpha x - \alpha y + x^{\prime} - y^{\prime}
  \end{pmatrix} \\
& = \alpha \begin{pmatrix}
    x + y \\
    x - y
  \end{pmatrix}
    + \begin{pmatrix}
    x^{\prime} + y^{\prime} \\
    x^{\prime} - y^{\prime}
  \end{pmatrix} \\
& = \alpha f\begin{pmatrix}x \\ y\end{pmatrix}
    + f\begin{pmatrix}x^{\prime} \\ y^{\prime}\end{pmatrix}
\end{split}
$$

(f) is a linear function.
