# Problem 4.7.7

$\mathbf{T} : \mathcal{R}^2 \rarr \mathcal{R}^3 $

$\mathbf{T}\left(x,y\right) = \left(x + 3y, 0, 2x - 4y\right)$

***
(a)

$$
\mathcal{S} = \left\{
  \begin{pmatrix}
    1 \\ 0
  \end{pmatrix},
  \begin{pmatrix}
    0 \\ 1
  \end{pmatrix}
\right\}
$$

$$
\mathcal{S}^{\prime} = \left\{
  \begin{pmatrix}
    1 \\ 0 \\ 0
  \end{pmatrix},
  \begin{pmatrix}
    0 \\ 1 \\ 0
  \end{pmatrix},
  \begin{pmatrix}
    0 \\ 0 \\ 1
  \end{pmatrix}
\right\}
$$

$$
\begin{split}
\mathbf{T}\left(\mathbf{u}_1\right) & = \left(1,0,2\right) \\
\mathbf{T}\left(\mathbf{u}_2\right) & = \left(3,0,-4\right)
\end{split}
$$

Find $ \left[\mathbf{T}\right]_{\mathcal{S}\mathcal{S}^{\prime}} $.

$$
\left[
    \mathbf{T}\left(\mathbf{u}_1\right)
    \right]_{\mathcal{S}\mathcal{S}^\prime}
  = \alpha_{11}\mathbf{v}_1 + \alpha_{21}\mathbf{v}_2 + \alpha_{31}\mathbf{v}_3
  = \begin{pmatrix}1 \\ 0 \\ 2\end{pmatrix}
$$

$$
\begin{pmatrix}
  \alpha_{11} \\
  \alpha_{21} \\
  \alpha_{31}
\end{pmatrix} =
\begin{pmatrix}
  1 \\
  0 \\
  2
\end{pmatrix}
$$

$$
\left[\mathbf{T}\left(\mathbf{u}_2\right)\right]_{\mathcal{S}\mathcal{S}^\prime}
  = \alpha_{12}\mathbf{v}_1 + \alpha_{22}\mathbf{v}_2 + \alpha_{32}\mathbf{v}_3
  = \begin{pmatrix}3 \\ 0 \\ -4\end{pmatrix}
$$

$$
\begin{pmatrix}
  \alpha_{12} \\
  \alpha_{22} \\
  \alpha_{32}
\end{pmatrix} =
\begin{pmatrix}
  3 \\
  0 \\
  -4
\end{pmatrix}
$$

$$
\left[\mathbf{T}\right]_{\mathcal{S}\mathcal{S}^{\prime}} =
  \begin{pmatrix}
    1 & 3 \\
    0 & 0 \\
    2 & -4
  \end{pmatrix}
$$

***

(b)

$$
\mathcal{S}^{\prime\prime} = \left\{
  \begin{pmatrix}
    0 \\ 0 \\ 1
  \end{pmatrix},
  \begin{pmatrix}
    0 \\ 1 \\ 0
  \end{pmatrix},
  \begin{pmatrix}
    1 \\ 0 \\ 0
  \end{pmatrix}
\right\}
$$

$$
\begin{split}
\mathbf{T}\left(\mathbf{u}_1\right) & = \left(1,0,2\right) \\
\mathbf{T}\left(\mathbf{u}_2\right) & = \left(3,0,-4\right)
\end{split}
$$

Find $ \left[\mathbf{T}\right]_{\mathcal{S}\mathcal{S}^{\prime\prime}} $.

$$
\left[
    \mathbf{T}\left(\mathbf{u}_1\right)
    \right]_{\mathcal{S}\mathcal{S}^{\prime\prime}}
  = \alpha_{11}\mathbf{v}_1 + \alpha_{21}\mathbf{v}_2 + \alpha_{31}\mathbf{v}_3
  = \begin{pmatrix}1 \\ 0 \\ 2\end{pmatrix}
$$

$$
\begin{pmatrix}
  \alpha_{11} \\
  \alpha_{21} \\
  \alpha_{31}
\end{pmatrix} =
\begin{pmatrix}
  2 \\
  0 \\
  1
\end{pmatrix}
$$

$$
\left[
    \mathbf{T}\left(\mathbf{u}_2\right)
    \right]_{\mathcal{S}\mathcal{S}^{\prime\prime}}
  = \alpha_{12}\mathbf{v}_1 + \alpha_{22}\mathbf{v}_2 + \alpha_{32}\mathbf{v}_3
  = \begin{pmatrix}3 \\ 0 \\ -4\end{pmatrix}
$$

$$
\begin{pmatrix}
  \alpha_{12} \\
  \alpha_{22} \\
  \alpha_{32}
\end{pmatrix} =
\begin{pmatrix}
  -4 \\
  0 \\
  3
\end{pmatrix}
$$

$$
\left[\mathbf{T}\right]_{\mathcal{S}\mathcal{S}^{\prime\prime}} =
  \begin{pmatrix}
    2 & -4 \\
    0 & 0 \\
    1 & 3
  \end{pmatrix}
$$
