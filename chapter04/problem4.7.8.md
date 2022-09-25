# Problem 4.7.8

$ \mathbf{T}\left(x, y, z\right)=\left(x-y, y-x, x-z\right) $

$ \mathbf{v} = \begin{pmatrix} 1 \\ 1 \\ 2 \end{pmatrix},
\mathcal{B} = \left\{
  \begin{pmatrix}1 \\ 0 \\ 1\end{pmatrix},
  \begin{pmatrix}0 \\ 1 \\ 1\end{pmatrix},
  \begin{pmatrix}1 \\ 1 \\ 0\end{pmatrix}
\right\}
$

***

(a) Determine $\left[\mathbf{T}\right]_{\mathcal{B}}$ and
  $\left[\mathbf{v}\right]_{\mathcal{B}}$.

$$
\mathcal{B} = \left\{\mathbf{u}_1, \mathbf{u}_2, \mathbf{u}_3\right\}
$$

$$
\left[\mathbf{T}\left(\mathbf{u}_1\right)\right]_{\mathcal{B}} =
  \alpha_{11}\mathbf{u}_1 + \alpha_{21}\mathbf{u}_2 + \alpha_{31}\mathbf{u}_3 =
  \begin{pmatrix} 1 \\ -1 \\ 0\end{pmatrix}
$$

$$
\begin{pmatrix}\alpha_{11} \\ \alpha_{21} \\ \alpha_{31}\end{pmatrix} =
\begin{pmatrix}1 \\ -1 \\ 0\end{pmatrix}
$$

$$
\left[\mathbf{T}\left(\mathbf{u}_2\right)\right]_{\mathcal{B}} =
  \alpha_{12}\mathbf{u}_1 + \alpha_{22}\mathbf{u}_2 + \alpha_{32}\mathbf{u}_3 =
  \begin{pmatrix} -1 \\ 1 \\ -1\end{pmatrix}
$$

$$
\begin{pmatrix}\alpha_{12} \\ \alpha_{22} \\ \alpha_{32}\end{pmatrix} =
\begin{pmatrix}-3/2 \\ 1/2  \\ 1/2\end{pmatrix}
$$

$$
\left[\mathbf{T}\left(\mathbf{u}_3\right)\right]_{\mathcal{B}} =
  \alpha_{13}\mathbf{u}_1 + \alpha_{23}\mathbf{u}_2 + \alpha_{33}\mathbf{u}_3 =
  \begin{pmatrix} 0 \\ 0 \\ 1\end{pmatrix}
$$

$$
\begin{pmatrix}\alpha_{13} \\ \alpha_{23} \\ \alpha_{33}\end{pmatrix} =
\begin{pmatrix} 1/2 \\ 1/2  \\ -1/2\end{pmatrix}
$$

$$
\left[\mathbf{T}\right]_{\mathcal{B}} = \begin{pmatrix}
  1 & -3/2 & 1/2 \\
  -1 & 1/2 & 1/2 \\
  0 & 1/2 & -1/2
\end{pmatrix}
$$

$$
\mathbf{v} =
  \beta_1\mathbf{u}_1 + \beta_2\mathbf{u}_2 + \beta_3\mathbf{u}_3 =
  \begin{pmatrix} 1 \\ 1 \\ 2\end{pmatrix}
$$

$$
\left[\mathbf{v}\right]_{\mathcal{B}} =
  \begin{pmatrix}1 \\ 1 \\ 0\end{pmatrix}
$$

***

(b) Compute $\left[\mathbf{T}\left(\mathbf{v}\right)\right]_{\mathcal{B}}$, and
then verify that $\left[\mathbf{T}\right]_{\mathcal{B}}
  \left[\mathbf{v}\right]_{\mathcal{B}} =
  \left[\mathbf{T}\left(\mathbf{v}\right)\right]_{\mathcal{B}}$.

$$
\mathbf{T}\left(\mathbf{v}\right) =
  \begin{pmatrix} 0 \\ 0 \\ -1 \end{pmatrix}
$$

$$
\alpha_1\mathbf{u}_1 + \alpha_2\mathbf{u}_2 + \alpha_3\mathbf{u}_3 =
  \begin{pmatrix} 0 \\ 0 \\ -1 \end{pmatrix}
$$

$$
\left[\mathbf{T}\left(\mathbf{v}\right)\right]_{\mathcal{B}} =
  \begin{pmatrix} -1/2 \\ -1/2 \\ 1/2 \end{pmatrix}
$$

$$
\left[\mathbf{T}\right]_{\mathcal{B}}\left[\mathbf{v}\right]_{\mathcal{B}} =
  \begin{pmatrix}
    1 & -3/2 & 1/2 \\
    -1 & 1/2 & 1/2 \\
    0 & 1/2 & -1/2
  \end{pmatrix}
  \begin{pmatrix}1 \\ 1 \\ 0\end{pmatrix} =
  \begin{pmatrix} -1/2 \\ -1/2 \\ 1/2 \end{pmatrix} =
  \left[\mathbf{T}\left(\mathbf{v}\right)\right]_{\mathcal{B}}
$$
