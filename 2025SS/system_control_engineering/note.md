# システム制御工学ノート

--- PAGE 1 ---

(空白ページ)

--- PAGE 2 ---

戦略

タンクに一定量水を貯めることを考える。

戦略1
・初めから全力 → あふれやすい

こういった自動化
現行は、機械で自動制御

まとめ。
制御とは対象物にはたらきかけて思う通りに動かすこと。

手動制御：ハンドル、アクセル、ブレーキ
自動制御：冷暖房機

制御工学とは。
・機械装置の制御に関する技術の集大成 [cite: 1]
・数学的な表現と方法論
    ・制御対象の動的表現
    ・働きかけ
    ・結果としての応答の計算 [cite: 1]

--- PAGE 3 ---

## 1.3 制御系の基本 (p5) [cite: 2]

ワットの調速機のモデル化 [cite: 2]

目標速度：おもりを上げる
調速機：弁の開度
弁：蒸気量
蒸気タービン：回転
負荷

現在の速度と比較して蒸気量を決める回転機構 [cite: 2]

このような関係を表現する方法をブロック線図という。 [cite: 2]

一般的表現

目標値 → 制御装置 → 操作量 → 制御対象 → 制御結果
          ↑                             ↓
          ---------------------------------
                  フィードバック

フィードバック($フィードバック$)制御系と呼ぶ。 [cite: 2]

開ループ制御系
目標値 → 制御装置 → 操作量 → 制御対象 → 制御結果
例：タイマー、ヒーター [cite: 2]

--- PAGE 4 ---

e.g. トースター・焼きすぎがありえる [cite: 3]

| 構造        | 開ループ                                                                 | 閉ループ (フィードバック)                                          |
| ----------- | ------------------------------------------------------------------------ | ------------------------------------------------------------------- |
|             | シンプル → 安い                                                           | 安定、調整不要                                                        |
|             | 外乱に弱い、調整必要                                                         | 複雑 → 高い                                                           |
|             | 使いすぎは悪影響のおそれ                                                       | 使いすぎても大丈夫                                                       |
|             | 不安定になることはない                                                       | 不安定になる可能性あり                                                    | [cite: 4]

--- PAGE 5 ---

## 3.3 ブロック線図の等価変換 (P7) [cite: 5]

伝達関数 G
U (入力) → G → Y (出力)
$Y = G \cdot U$ で表現される [cite: 5]

[信号の加減算]
U → 〇 → Y
    ↑
    X
$Y = U \pm X$ と表現 [cite: 5]

[例1: 並列結合]
      G1
    ↗  ↘
U →     + → Y
    ↘  ↗
      G2

$Y = G_1 U + G_2 U$
$Y = (G_1 + G_2) U$ [cite: 5]

Simply:
$U \rightarrow G_1 + G_2 \rightarrow Y$ [cite: 5]

[例2: フィードバック結合]
U → 〇 → G1 → Y
    ↑-    ↓
    G2 Y   G2

$Y = G_1 (U - G_2 Y)$
$Y = G_1 U - G_1 G_2 Y$
$(1 + G_1 G_2) Y = G_1 U$
$Y = \frac{G_1 U}{1 + G_1 G_2}$ [cite: 5]

$U \rightarrow \frac{G_1}{1 + G_1 G_2} \rightarrow Y$ [cite: 5]

--- PAGE 6 ---

(ブロック線図の図) [cite: 6]
U → G3 --------------------→ + → G2 → Y
↓↘                              ↑
〇 → G1 → G1(U-Y) ---→+
↑-                            ↑
Y ---------------------------

$Y = (G_1(U-Y) + G_3 U) G_2$ [cite: 6]
$Y = G_1 G_2 U - G_1 G_2 Y + G_2 G_3 U$ [cite: 6]
$(1 + G_1 G_2) Y = (G_1 G_2 + G_2 G_3) U$ (※元の式は $(G_1+G_3)G_2 U$ となっていますが、展開すると $G_1G_2U + G_2G_3U$ です)
$Y = \frac{(G_1 + G_3)G_2}{1 + G_1 G_2} U$ [cite: 6]

--- PAGE 7 ---

練習問題 [cite: 7]

自動制御の例：暖房 [cite: 7]
目標温度と現在の温度を比較し、温度計のデータから、現在の温度と目標温度の差異を計算、それに応じて風の温度や強度を調整する。常に計測と調整を繰り返し、目標値を維持する（目標値に近づいたら温度を下げる）。 [cite: 7]
内部温度計 → 現在の温度 [cite: 7]

手動制御の例：電子レンジ [cite: 7]
予め設定された電力(W)、時間(t)により、対象を決められた熱量 Wt の分だけマイクロ波で加熱する。対象の温度などの計測はしない。 [cite: 7]
マイクロ波 → 対象（食べもの） [cite: 7]

(電子レンジの図) [cite: 7]

--- PAGE 8 ---

問2 暖房のブロック線図 [cite: 8]
目標温度 U → 〇 → G1 → + → G3 → Y (現在の温度)
              ↑-       ↑
              Y        G2(U-Y) ← G2 ← 〇 ← U
                                      ↑-
                                      Y

G1: 指令部
G2: 検出部 (温度計)
G3: 操作部 (ヒーター、ファン)
操作量：電力、風の温度、風の強さ
フィードバック [cite: 8]

問3
$Y = G_3 \{ G_1 U + G_2 (U-Y) \}$ [cite: 8]
$Y = G_1 G_3 U + G_2 G_3 U - G_2 G_3 Y$ [cite: 8]
$(1 + G_2 G_3) Y = (G_1 + G_2) G_3 U$ [cite: 8]
$Y = \frac{(G_1 + G_2)G_3}{1 + G_2 G_3} U$ [cite: 8]
温風 [cite: 8]

(ブロック線図の図) [cite: 8]

--- PAGE 9 ---

練習問題 (※ PAGE 7 と同じ内容の繰り返し) [cite: 9]

自動制御の例：暖房 [cite: 9]
目標温度と現在の温度を比較し、温度計のデータから、現在の温度と目標温度の差異を計算、それに応じて風の温度や強度を調整する。常に計測と調整を繰り返し、目標値を維持する（目標値に近づいたら温度を下げる）。 [cite: 9]
内部温度計 → 現在の温度 [cite: 9]

手動制御の例：電子レンジ [cite: 9]
予め設定された電力(W)、時間(t)により、対象を決められた熱量 Wt の分だけマイクロ波で加熱する。対象の温度などの計測はしない。 [cite: 9]
マイクロ波 → 対象（食べもの） [cite: 9]

(電子レンジの図) [cite: 9]

--- PAGE 10 ---

問2 暖房のブロック線図 (※ PAGE 8 と同じ内容の繰り返し) [cite: 10]
目標温度 U → 〇 → G1 → + → G3 → Y (現在の温度)
              ↑-       ↑
              Y        G2(U-Y) ← G2 ← 〇 ← U
                                      ↑-
                                      Y

G1: 指令部
G2: 検出部 (温度計)
G3: 操作部 (ヒーター、ファン)
操作量：電力、風の温度、風の強さ
フィードバック [cite: 10]

問3
$Y = G_3 \{ G_1 U + G_2 (U-Y) \}$ [cite: 10]
$Y = G_1 G_3 U + G_2 G_3 U - G_2 G_3 Y$ [cite: 10]
$(1 + G_2 G_3) Y = (G_1 + G_2) G_3 U$ [cite: 10]
$Y = \frac{(G_1 + G_2)G_3}{1 + G_2 G_3} U$ [cite: 10]
温風 [cite: 10]

(ブロック線図の図) [cite: 10]

--- PAGE 11 ---

## ラプラス変換 [cite: 11]

$L[f(t)] = F(s) = \int_0^\infty f(t) e^{-st} dt$ [cite: 11]

--- PAGE 12 ---

例2.8 (P32) [cite: 12]
$F(s) = \frac{3s^2 + (\sqrt{3}+5)s + 4}{2s(s^2+2s+2)}$ --- (1) [cite: 12]
分母 $= 2s(s^2+2s+2)$
$s^2+2s+2=0 \implies s = \frac{-2 \pm \sqrt{4-8}}{2} = \frac{-2 \pm 2i}{2} = -1 \pm i$ [cite: 12]
分母 $= 2s(s+1-i)(s+1+i)$ [cite: 12]

$F(s) = \frac{K_1}{s} + \frac{K_2}{s+1-i} + \frac{K_3}{s+1+i}$ --- (2) [cite: 12]
展開して係数比較
分子 $= K_1(s^2+2s+2) + K_2 s(s+1+i) + K_3 s(s+1-i)$ [cite: 12]
$= (K_1+K_2+K_3)s^2 + (2K_1+(1+i)K_2+(1-i)K_3)s + 2K_1$ [cite: 12]

これと(1)の分子 $ \frac{1}{2} (3s^2 + (\sqrt{3}+5)s + 4) = \frac{3}{2}s^2 + \frac{\sqrt{3}+5}{2}s + 2$ を比較

$2K_1 = 2 \implies K_1 = 1$ [cite: 12]
$K_1+K_2+K_3 = \frac{3}{2} \implies K_2+K_3 = \frac{1}{2}$ [cite: 12]
$2K_1+(1+i)K_2+(1-i)K_3 = \frac{\sqrt{3}+5}{2}$
$2+(1+i)K_2+(1-i)K_3 = \frac{\sqrt{3}+5}{2}$
$(1+i)K_2+(1-i)K_3 = \frac{\sqrt{3}+1}{2}$ [cite: 12]

$K_3 = \frac{1}{2} - K_2$ を代入
$(1+i)K_2 + (1-i)(\frac{1}{2}-K_2) = \frac{\sqrt{3}+1}{2}$ [cite: 12]
$(1+i)K_2 + \frac{1-i}{2} - (1-i)K_2 = \frac{\sqrt{3}+1}{2}$ [cite: 12]
$2i K_2 = \frac{\sqrt{3}+1}{2} - \frac{1-i}{2} = \frac{\sqrt{3}+i}{2}$
$K_2 = \frac{\sqrt{3}+i}{4i} = \frac{(\sqrt{3}+i)(-i)}{4i(-i)} = \frac{-i\sqrt{3}+1}{4} = \frac{1-i\sqrt{3}}{4}$ (※ノートの $K_2 = \frac{1+i\sqrt{3}}{4}$ と符号が異なります) [cite: 12]
$K_3 = \frac{1}{2} - \frac{1-i\sqrt{3}}{4} = \frac{2 - (1-i\sqrt{3})}{4} = \frac{1+i\sqrt{3}}{4}$ (※ノートの $K_3 = \frac{1-i\sqrt{3}}{4}$ と符号が異なります) [cite: 12]

(ノートの計算結果)
$K_1=1, K_2=\frac{1+i\sqrt{3}}{4}, K_3=\frac{1-i\sqrt{3}}{4}$ [cite: 12]

--- PAGE 13 ---

$f(t) = L^{-1}[F(s)]$ [cite: 13]
$= K_1 + K_2 e^{(-1+i)t} + K_3 e^{(-1-i)t}$ (※指数の符号がノートと異なります)
$= K_1 + e^{-t}(K_2 e^{it} + K_3 e^{-it})$
$= K_1 + e^{-t}(K_2(\cos t + i \sin t) + K_3(\cos t - i \sin t))$
$= K_1 + e^{-t}((K_2+K_3)\cos t + i(K_2-K_3)\sin t)$ [cite: 13]

$K_2+K_3 = \frac{1+i\sqrt{3}}{4} + \frac{1-i\sqrt{3}}{4} = \frac{2}{4} = \frac{1}{2}$ [cite: 13]
$K_2-K_3 = \frac{1+i\sqrt{3}}{4} - \frac{1-i\sqrt{3}}{4} = \frac{2i\sqrt{3}}{4} = \frac{i\sqrt{3}}{2}$ [cite: 13]

$f(t) = 1 + e^{-t}(\frac{1}{2}\cos t + i(\frac{i\sqrt{3}}{2})\sin t)$
$= 1 + e^{-t}(\frac{1}{2}\cos t - \frac{\sqrt{3}}{2}\sin t)$ (※ノートの $\sin t$ の係数の符号が異なります) [cite: 13]
$= 1 + e^{-t} (\cos(\frac{\pi}{3})\cos t - \sin(\frac{\pi}{3})\sin t)$
$= 1 + e^{-t} \cos(t+\frac{\pi}{3})$ (※ノートは $1+e^{-t}\sin(t+\frac{\pi}{6})$) [cite: 13]

例2.10 (P33) [cite: 13]
$y' + ay = 1$, ($y(0)=2, a \neq 0$) [cite: 13]
ラプラス変換すると、
$sY(s) - y(0) + aY(s) = \frac{1}{s}$ [cite: 13]
$(s+a)Y(s) = \frac{1}{s} + 2$
$Y(s) = \frac{1}{s+a}(\frac{1+2s}{s}) = \frac{1+2s}{s(s+a)}$ [cite: 13]
部分分数分解
$\frac{1+2s}{s(s+a)} = \frac{A}{s} + \frac{B}{s+a} = \frac{A(s+a)+Bs}{s(s+a)}$
$A(s+a)+Bs = (A+B)s + Aa = 1+2s$
$Aa = 1 \implies A = \frac{1}{a}$
$A+B = 2 \implies B = 2-A = 2-\frac{1}{a}$
$Y(s) = \frac{1}{a}\frac{1}{s} + (2-\frac{1}{a})\frac{1}{s+a}$ [cite: 13]

--- PAGE 14 ---

$y(t) = L^{-1}[Y(s)]$ [cite: 14]
$= \frac{1}{a} L^{-1}[\frac{1}{s}] + (2-\frac{1}{a}) L^{-1}[\frac{1}{s+a}]$ [cite: 14]
$= \frac{1}{a} \cdot 1 + (2-\frac{1}{a}) e^{-at}$ [cite: 14]
$y(t) = \frac{1}{a} + (2-\frac{1}{a})e^{-at}$ [cite: 14]

--- PAGE 15 ---

例2.11 (P34) [cite: 15]
$y'' + 2y' + 2y = \sin(2t)$, $y(0)=0, y'(0)=1$ [cite: 15]
ラプラス変換すると
$s^2 Y(s) - sy(0) - y'(0) + 2(sY(s) - y(0)) + 2Y(s) = \frac{2}{s^2+4}$ [cite: 15]
$s^2 Y(s) - 1 + 2sY(s) + 2Y(s) = \frac{2}{s^2+4}$ [cite: 15]
$(s^2+2s+2)Y(s) = \frac{2}{s^2+4} + 1 = \frac{2+s^2+4}{s^2+4} = \frac{s^2+6}{s^2+4}$ [cite: 15]
$Y(s) = \frac{s^2+6}{(s^2+4)(s^2+2s+2)}$ [cite: 15]
仮定: $Y(s) = \frac{As+B}{s^2+4} + \frac{Cs+D}{s^2+2s+2}$ [cite: 15]
(計算略)
$Y(s) = \frac{1}{5}\frac{s+8}{s^2+2s+2} - \frac{1}{5}\frac{s-2}{s^2+4}$ (※ノートの $\frac{s+1}{s^2+4}$ と符号が異なります) [cite: 15]
$\frac{s+8}{(s+1)^2+1} = \frac{s+1}{(s+1)^2+1} + \frac{7}{(s+1)^2+1}$ [cite: 15]
$\frac{s-2}{s^2+4} = \frac{s}{s^2+2^2} - \frac{2}{s^2+2^2} = \frac{s}{s^2+2^2} - \frac{1}{2}\frac{2 \cdot 1}{s^2+2^2}$ (※ノートの $\frac{s+1/2 \cdot 2}{s^2+4}$ の部分は $\frac{s}{s^2+4} + \frac{1}{s^2+4}$ に対応か)

$Y(s) = \frac{1}{5} \left( \frac{s+1}{(s+1)^2+1} + \frac{7}{(s+1)^2+1} \right) - \frac{1}{5} \left( \frac{s}{s^2+4} - \frac{2}{s^2+4} \right)$
(ノートの式展開)
$Y = \frac{1}{5}\frac{s+1}{(s+1)^2+1} + \frac{7}{5}\frac{1}{(s+1)^2+1} - \frac{1}{5}\frac{s}{s^2+4} + \frac{2}{5}\frac{1}{s^2+4}$ (※最後の項の符号がノートと異なる) [cite: 15]

--- PAGE 16 ---

(前のページの続き、ノートの式展開の逆ラプラス変換)
$y(t) = L^{-1}[Y(s)]$ [cite: 16]
$= \frac{1}{5}e^{-t}\cos t + \frac{7}{5}e^{-t}\sin t - \frac{1}{5}\cos 2t + \frac{2}{5} \cdot \frac{1}{2} \sin 2t$ (※ノートの $-\frac{1}{10}\sin 2t$ と一致しない)
$= \frac{1}{5}e^{-t}\cos t + \frac{7}{5}e^{-t}\sin t - \frac{1}{5}\cos 2t + \frac{1}{5}\sin 2t$
(ノートの解答)
$y(t) = \frac{1}{5}e^{-t}\cos t + \frac{7}{5}e^{-t}\sin t - \frac{1}{5}\cos 2t - \frac{1}{10}\sin 2t$ [cite: 16]

--- PAGE 17 ---

例2.12 (P.35) [cite: 17]
$y' + y = f(t)$, $y(0)=0$ [cite: 17]
$f(t) = \begin{cases} 1 & 0 \le t < 1 \\ 0 & 1 \le t \end{cases}$ [cite: 17]
$f(t) = u_s(t) - u_s(t-1)$ (ここで $u_s(t)$ は単位ステップ関数) [cite: 17]
$L[f(t)] = \frac{1}{s} - e^{-s}\frac{1}{s} = \frac{1-e^{-s}}{s}$ [cite: 17]

ラプラス変換する。
$sY(s) - y(0) + Y(s) = \frac{1-e^{-s}}{s}$ [cite: 17]
$(s+1)Y(s) = \frac{1-e^{-s}}{s}$
$Y(s) = \frac{1-e^{-s}}{s(s+1)} = \frac{1}{s(s+1)} - \frac{e^{-s}}{s(s+1)}$ [cite: 17]
$\frac{1}{s(s+1)} = \frac{1}{s} - \frac{1}{s+1}$
$Y(s) = (\frac{1}{s} - \frac{1}{s+1}) - e^{-s}(\frac{1}{s} - \frac{1}{s+1})$ [cite: 17]
$Y(s) = \frac{1}{s} - \frac{1}{s+1} - e^{-s}\frac{1}{s} + e^{-s}\frac{1}{s+1}$ [cite: 17]

$y(t) = L^{-1}[\frac{1}{s}] - L^{-1}[\frac{1}{s+1}] - L^{-1}[e^{-s}\frac{1}{s}] + L^{-1}[e^{-s}\frac{1}{s+1}]$
$y(t) = 1 - e^{-t} - u_s(t-1) \cdot 1 + u_s(t-1) e^{-(t-1)}$ [cite: 17]
$y(t) = (1 - e^{-t}) - u_s(t-1)(1 - e^{-(t-1)})$ (ノートの最後の式と一致) [cite: 17]

--- PAGE 18 ---

問1 [cite: 18]
(1) $L[t \sin t]$ [cite: 18]
$L[\sin t] = \frac{1}{s^2+1}$
$L[t f(t)] = -\frac{d}{ds}F(s)$
$L[t \sin t] = -\frac{d}{ds} (\frac{1}{s^2+1}) = -(-1)(s^2+1)^{-2}(2s) = \frac{2s}{(s^2+1)^2}$ [cite: 18]

(2) $f(t) = te^{-at} \sin(\omega t)$ (※ノートでは $2e^{-at}\sin(\omega t)$ の微分をしているように見える) [cite: 18]
$L[e^{-at}\sin(\omega t)] = \frac{\omega}{(s+a)^2+\omega^2}$
$L[t e^{-at}\sin(\omega t)] = -\frac{d}{ds} \left( \frac{\omega}{(s+a)^2+\omega^2} \right)$ [cite: 18]
$= -\omega (-( (s+a)^2+\omega^2 )^{-2} \cdot 2(s+a) )$
$= \frac{2\omega(s+a)}{((s+a)^2+\omega^2)^2}$ [cite: 18]

問2 [cite: 18]
(1) $F(s) = \frac{s}{s^2+16} = \frac{s}{s^2+4^2}$ [cite: 18]
$L^{-1}[F(s)] = \cos(4t)$ (※ノートでは $\cos(2t)$) [cite: 18]

(2) $F(s) = \frac{2s+5}{(s+1)^2} = \frac{A}{s+1} + \frac{B}{(s+1)^2}$ [cite: 18]
$\frac{A(s+1)+B}{(s+1)^2} = \frac{As+A+B}{(s+1)^2}$ [cite: 18]

--- PAGE 19 ---

これと①($\frac{2s+5}{(s+1)^2}$)を比較する [cite: 19]
$A=2$ [cite: 19]
$A+B=5 \implies 2+B=5 \implies B=3$ [cite: 19]
$F(s) = \frac{2}{s+1} + \frac{3}{(s+1)^2}$ [cite: 19]
$L^{-1}[F(s)] = 2e^{-t} + 3te^{-t}$ [cite: 19]

(3) $F(s) = \frac{2s^2+3s+3}{s^3+6s^2+11s+6}$ [cite: 19]
分母 $s^3+6s^2+11s+6 = (s+1)(s+2)(s+3)$ [cite: 19]
$\frac{2s^2+3s+3}{(s+1)(s+2)(s+3)} = \frac{A}{s+1} + \frac{B}{s+2} + \frac{C}{s+3}$ [cite: 19]
分子 $= A(s+2)(s+3) + B(s+1)(s+3) + C(s+1)(s+2)$
$= A(s^2+5s+6) + B(s^2+4s+3) + C(s^2+3s+2)$
$= (A+B+C)s^2 + (5A+4B+3C)s + (6A+3B+2C)$ [cite: 19]

これを $2s^2+3s+3$ と比較すると、
$\begin{cases} A+B+C=2 \\ 5A+4B+3C=3 \\ 6A+3B+2C=3 \end{cases}$ [cite: 19]
(計算省略)
$A=1, B=-5, C=6$ (※ノートの解と一致) [cite: 19]
$F(s) = \frac{1}{s+1} - \frac{5}{s+2} + \frac{6}{s+3}$ [cite: 19]

--- PAGE 20 ---

$L^{-1}[F(s)] = e^{-t} - 5e^{-2t} + 6e^{-3t}$ (※ノートでは $-5/2 e^{-2t} + 2e^{-3t}$ のように見えるが、行列計算の結果は $A=1, B=-5, C=6$ になっている) [cite: 20]

問3 [cite: 20]
(1) $y'' + y = 0$, $y(0)=1, y'(0)=2$ [cite: 20]
両辺をラプラス変換する
$s^2 Y(s) - sy(0) - y'(0) + Y(s) = 0$ [cite: 20]
$(s^2+1)Y(s) - s - 2 = 0$ (※ノートでは $Y-s+1-2=0$ のように見えるが、$Y(s)$ が抜けている)
$Y(s) = \frac{s+2}{s^2+1} = \frac{s}{s^2+1} + 2\frac{1}{s^2+1}$ [cite: 20]
これを逆ラプラス変換する。
$L^{-1}[Y(s)] = \cos t + 2 \sin t$ [cite: 20]
$y(t) = \cos t + 2 \sin t$ [cite: 20]

--- PAGE 21 ---

(2) $y'' + 3y' + 4y = 0$, $y(0)=1, y'(0)=1$ [cite: 21]
両辺をラプラス変換すると
$s^2 Y(s) - sy(0) - y'(0) + 3(sY(s) - y(0)) + 4Y(s) = 0$ [cite: 21]
$s^2 Y(s) - s - 1 + 3sY(s) - 3 + 4Y(s) = 0$ [cite: 21]
$(s^2+3s+4)Y(s) = s+4$ (※ノートでは $s+9$ に見える) [cite: 21]
$Y(s) = \frac{s+4}{s^2+3s+4}$ [cite: 21]
$s^2+3s+4 = (s+\frac{3}{2})^2 - \frac{9}{4} + 4 = (s+\frac{3}{2})^2 + \frac{7}{4}$ [cite: 21]
$Y(s) = \frac{s+\frac{3}{2} + \frac{5}{2}}{(s+\frac{3}{2})^2 + (\frac{\sqrt{7}}{2})^2} = \frac{s+\frac{3}{2}}{(s+\frac{3}{2})^2 + (\frac{\sqrt{7}}{2})^2} + \frac{\frac{5}{2}}{\frac{\sqrt{7}}{2}} \frac{\frac{\sqrt{7}}{2}}{(s+\frac{3}{2})^2 + (\frac{\sqrt{7}}{2})^2}$
$Y(s) = \frac{s+\frac{3}{2}}{(s+\frac{3}{2})^2 + (\frac{\sqrt{7}}{2})^2} + \frac{5}{\sqrt{7}} \frac{\frac{\sqrt{7}}{2}}{(s+\frac{3}{2})^2 + (\frac{\sqrt{7}}{2})^2}$ [cite: 21]
逆ラプラス変換する。
$y(t) = e^{-\frac{3}{2}t} \cos(\frac{\sqrt{7}}{2}t) + \frac{5}{\sqrt{7}} e^{-\frac{3}{2}t} \sin(\frac{\sqrt{7}}{2}t)$ [cite: 21]

(3) $y'' - 3y' + 2y = e^{2t}$, $y(0)=0, y'(0)=-1$ [cite: 21]
両辺をラプラス変換する
$s^2 Y(s) - sy(0) - y'(0) - 3(sY(s) - y(0)) + 2Y(s) = \frac{1}{s-2}$ [cite: 21]
$s^2 Y(s) - (-1) - 3sY(s) + 2Y(s) = \frac{1}{s-2}$ [cite: 21]
$(s^2-3s+2)Y(s) = \frac{1}{s-2} - 1 = \frac{1-(s-2)}{s-2} = \frac{3-s}{s-2}$ (※ノートでは $\frac{-s+3}{s-2}$) [cite: 21]

--- PAGE 22 ---

$(s-1)(s-2)Y(s) = \frac{3-s}{s-2}$ [cite: 22]
$Y(s) = \frac{3-s}{(s-1)(s-2)^2}$ --- (1) [cite: 22]
$Y(s) = \frac{A}{s-1} + \frac{B}{s-2} + \frac{C}{(s-2)^2}$ [cite: 22]
分子 $= A(s-2)^2 + B(s-1)(s-2) + C(s-1)$
$= A(s^2-4s+4) + B(s^2-3s+2) + C(s-1)$
$= (A+B)s^2 + (-4A-3B+C)s + (4A+2B-C)$ [cite: 22]

①と比較して ($0s^2 -s + 3$)
$\begin{cases} A+B=0 \\ -4A-3B+C=-1 \\ 4A+2B-C=3 \end{cases}$ [cite: 22]
(計算省略)
$A=2, B=-2, C=1$ (※ノートの解と一致) [cite: 22]
$Y(s) = \frac{2}{s-1} - \frac{2}{s-2} + \frac{1}{(s-2)^2}$ [cite: 22]
逆ラプラス変換すると、
$y(t) = 2e^t - 2e^{2t} + te^{2t}$ [cite: 22]

--- PAGE 23 ---

# 5 伝達関数 [cite: 23]
システム特性のラプラス関数表現

制御対象：バネマスダンパ系 [cite: 23]
質量: M (kg)
初期位置: $y_0$
バネ定数: K (N/m)
ダンパー粘性係数: D (Ns/m)
外力: u(t) (N)
変位: y(t) [cite: 23]

運動方程式を立てる
$M\ddot{y} = u(t) - D\dot{y} - Ky$ [cite: 23]
$M\ddot{y} + D\dot{y} + Ky = u(t)$ --- (3.1) [cite: 23]

入力 u(t) の種類
- ステップ入力 (押しっぱなし)
- インパルス入力 (衝撃力)
- 正弦波入力

これを解くと、$u(t)$ に対する $y(t)$ が得られる。
初期条件 $y(0), \dot{y}(0)$ [cite: 23]

ラプラス変換より、(初期条件 $y(0), y'(0)$)
$M(s^2 Y(s) - sy(0) - y'(0)) + D(sY(s) - y(0)) + KY(s) = U(s)$ --- (3.2) [cite: 23]
$Y(s)(Ms^2+Ds+K) - M(sy(0)+y'(0)) - Dy(0) = U(s)$
$Y(s) = \frac{1}{Ms^2+Ds+K} U(s) + \frac{M(sy(0)+y'(0)) + Dy(0)}{Ms^2+Ds+K}$ --- (3.3) [cite: 23]

--- PAGE 24 ---

$y(t) = L^{-1}\left[\frac{1}{Ms^2+Ds+K}U(s)\right] + L^{-1}\left[\frac{M(sy(0)+y'(0)) + Dy(0)}{Ms^2+Ds+K}\right]$ [cite: 24]

零状態応答 (入力への応答): $y(0)=y'(0)=0$ のとき [cite: 24]
3.3より
$Y(s) = \frac{1}{Ms^2+Ds+K} U(s)$ [cite: 24]
$Y(s) = G(s) U(s)$
ここで $G(s) = \frac{1}{Ms^2+Ds+K}$ を伝達関数という。システムの物理的特性の数学的表現。 [cite: 24]

零入力応答 (初期状態への応答): $U(s)=0$ のとき [cite: 24]

伝達関数 $G(s) = \frac{Y(s)}{U(s)}$ [cite: 24]

インパルス応答の計算 (p.49) [cite: 24]
条件 $M=K=1, D=0.6$, 初期条件 $y(0)=y'(0)=0$ [cite: 24]
この系に衝撃力を与えると？ (→ インパルス応答を計算) [cite: 24]

(グラフの予想図) [cite: 24]

まず入力関数
$u(t) = \delta(t)$ (デルタ関数) [cite: 24]
$L[u(t)] = L[\delta(t)] = 1$ [cite: 24]

--- PAGE 25 ---

よって、$Y(s) = G(s) \cdot 1 = G(s)$ [cite: 25]
$G(s) = \frac{1}{s^2+0.6s+1}$
$y(t) = g(t) = L^{-1}\left[\frac{1}{s^2+0.6s+1}\right]$ [cite: 25]
$= L^{-1}\left[\frac{1}{(s+0.3)^2 - 0.09 + 1}\right] = L^{-1}\left[\frac{1}{(s+0.3)^2 + 0.91}\right]$ [cite: 25]
$= L^{-1}\left[\frac{1}{(s+0.3)^2 + (\sqrt{0.91})^2}\right]$ [cite: 25]
$= L^{-1}\left[\frac{1}{\sqrt{0.91}} \frac{\sqrt{0.91}}{(s+0.3)^2 + (\sqrt{0.91})^2}\right]$ [cite: 25]
$= \frac{1}{\sqrt{0.91}} e^{-0.3t} \sin(\sqrt{0.91}t)$ [cite: 25]
$t=0$ で $y(0) = \frac{1}{\sqrt{0.91}} \cdot 1 \cdot \sin(0) = 0$ (動き出す) [cite: 25]

(インパルス応答のグラフ)
縦軸 $y(t)$, 横軸 $t$
$t=0$ で $y=0$ から始まり、正弦波的に振動しながら減衰する。
振幅のエンベロープは $\pm \frac{1}{\sqrt{0.91}} e^{-0.3t}$ [cite: 25]
バネの力で振動、ダンパーで減衰 [cite: 25]

--- PAGE 26 ---

伝達関数の一般化 (p.50) [cite: 26]
対象システムの運動方程式を一般化する。
$y^{(n)} + a_{n-1}y^{(n-1)} + \dots + a_0 y = b_m u^{(m)} + b_{m-1}u^{(m-1)} + \dots + b_0 u$ --- (3.8)
(※ノートの係数は $l_m, \dots, l_0$) [cite: 26]
$n, m \in Z, a_i, b_j$ は定数
初期条件は全て0。 [cite: 26]

3.8をラプラス変換する...
$Y(s)(s^n + a_{n-1}s^{n-1} + \dots + a_0) = U(s)(b_m s^m + b_{m-1}s^{m-1} + \dots + b_0)$ [cite: 26]
$\frac{Y(s)}{U(s)} = G(s) = \frac{b_m s^m + b_{m-1}s^{m-1} + \dots + b_0}{s^n + a_{n-1}s^{n-1} + \dots + a_0}$ --- (3.10) [cite: 26]

分母多項式 $=0$ の根 $p_1, p_2, \dots, p_n$ をシステムの極 (Pole) と呼ぶ。 [cite: 26]
分子多項式 $=0$ の根 $z_1, z_2, \dots, z_m$ をシステムの零点 (Zero) と呼ぶ。 [cite: 26]
$G(s) = \frac{b_m(s-z_1)(s-z_2)\dots(s-z_m)}{(s-p_1)(s-p_2)\dots(s-p_n)} = \frac{N(s)}{D(s)}$ --- (3.11) [cite: 26]
$n-m$: システムの相対次数

解を得るには分母を因数分解する。 [cite: 26]

--- PAGE 27 ---

制御では、極と零点が重要 [cite: 27]

1次遅れ系 (P52) [cite: 27]
$T \dot{y}(t) + y(t) = K u(t)$ --- (3.12) [cite: 27]
初期値すべて0
ラプラス変換
$TsY(s) + Y(s) = K U(s)$ [cite: 27]
$(Ts+1)Y(s) = K U(s)$ [cite: 27]
$G(s) = \frac{Y(s)}{U(s)} = \frac{K}{Ts+1}$ --- (3.13) 1次遅れの伝達関数 [cite: 27]
極 $s = -\frac{1}{T}$ [cite: 27]
T: 時定数。時定数が大きい → ゆっくり効いてくる、ということ [cite: 27]

例3.1 (P.52) RC回路を考える。 [cite: 27]
入力: $u_i(t)$ [V] (電源電圧)
出力: $u_o(t)$ [V] (コンデンサ電圧)
抵抗: R ($\Omega$)
コンデンサ: C (F)
電流: $i(t)$ [cite: 28]

コンデンサに注目すると
$Q = CV$
$i(t) = \frac{dQ}{dt} = C \frac{du_o(t)}{dt}$ [cite: 28]
$C \dot{u_o}(t) = i(t)$ [cite: 28]

--- PAGE 28 ---

キルヒホッフの電圧則より、
$u_i(t) = R i(t) + u_o(t)$ [cite: 29]
$u_i(t) = RC \dot{u_o}(t) + u_o(t)$ [cite: 29]
$RC \dot{y}(t) + y(t) = K u(t)$ (※ $u_i$ を $u$, $u_o$ を $y$, $K=1$ と対応)
3.13式と比較すると $T \rightarrow RC, K \rightarrow 1$ [cite: 29]
$G(s) = \frac{1}{RCs+1} = \frac{\frac{1}{RC}}{s+\frac{1}{RC}}$ (※ノートでは $G = \frac{K}{Ts+1} = \frac{K/T}{s+1/T}$ (3.18)) [cite: 29]

インパルス応答では、$U(s)=1$
$Y(s) = G(s)$
$y(t) = g(t) = L^{-1}\left[\frac{K/T}{s+1/T}\right] = \frac{K}{T} e^{-\frac{1}{T}t}$ [cite: 29]
$y(0) = g(0) = \frac{K}{T}$ [cite: 29]
$y'(0) = g'(0) = \frac{K}{T} (-\frac{1}{T}) e^0 = -\frac{K}{T^2}$ [cite: 29]
$y(\infty) = g(\infty) = \lim_{t\rightarrow\infty} \frac{K}{T} e^{-\frac{1}{T}t} = 0$ (最終値定理 $\lim_{s\rightarrow 0} sG(s) = \lim_{s\rightarrow 0} \frac{sK}{Ts+1} = 0$) [cite: 29]

(インパルス応答のグラフ)
入力はすぐに0に戻る
出力は遅れて0に戻る [cite: 29]

ステップ応答では、$U(s) = \frac{1}{s}$
$Y(s) = G(s) \frac{1}{s} = \frac{K}{Ts+1} \frac{1}{s}$ [cite: 29]
$= K (\frac{1}{s} - \frac{T}{Ts+1}) = K (\frac{1}{s} - \frac{1}{s+1/T})$
$y(t) = L^{-1}[Y(s)] = K (1 - e^{-\frac{1}{T}t})$ [cite: 29]

--- PAGE 29 ---

$y(t) = K(1-e^{-\frac{1}{T}t})$ (※ノートでは $k-ke^{-\frac{1}{T}t}$) [cite: 30]
$y(0) = K(1-e^0) = 0$ (初期値定理 $\lim_{s\rightarrow\infty} sY(s) = \lim_{s\rightarrow\infty} s \frac{K}{Ts+1}\frac{1}{s} = \lim_{s\rightarrow\infty} \frac{K}{Ts+1} = 0$) [cite: 30]
$y(\infty) = K(1-0) = K$ (最終値定理 $\lim_{s\rightarrow 0} sY(s) = \lim_{s\rightarrow 0} s \frac{K}{Ts+1}\frac{1}{s} = \lim_{s\rightarrow 0} \frac{K}{Ts+1} = K$) [cite: 30]
$y'(t) = K(0 - (-\frac{1}{T})e^{-\frac{1}{T}t}) = \frac{K}{T}e^{-\frac{1}{T}t}$
$y'(0) = \frac{K}{T}e^0 = \frac{K}{T}$ [cite: 30]

(ステップ応答のグラフ)
入力に対して出力が遅れて立ち上がり、Kに収束する。 → 一次遅れ [cite: 30]
$t=T$ (時定数) のとき $y(T) = K(1-e^{-1}) \approx 0.632K$

--- PAGE 30 ---

例 (RC回路、ステップ入力 $u_i(t)=1$ for $t \ge 0$) [cite: 31]
$u_i(t) = R i(t) + u_o(t)$
$i(t) = C \frac{du_o(t)}{dt}$
$1 = RC \frac{du_o(t)}{dt} + u_o(t)$ ($u_o(0)=0$)
ラプラス変換すると、$R=1, C=1$ (図より $R=2, C=3$ なら $RC=6$)
$\frac{1}{s} = RC(sU_o(s) - u_o(0)) + U_o(s)$
$\frac{1}{s} = (RCs+1)U_o(s)$
$U_o(s) = \frac{1}{s(RCs+1)} = \frac{1}{RC} \frac{1}{s(s+1/RC)}$
$= \frac{1}{RC} (RC (\frac{1}{s} - \frac{1}{s+1/RC})) = \frac{1}{s} - \frac{1}{s+1/RC}$ [cite: 31]
逆ラプラス変換
$u_o(t) = 1 - e^{-\frac{1}{RC}t}$ [cite: 31]
図のパラメータ $R=2, C=3$ なら $RC=6$
$u_o(t) = 1 - e^{-\frac{t}{6}}$ [cite: 31]
$u_o'(0) = \frac{1}{6}e^0 = \frac{1}{6}$ [cite: 31]

(グラフ)
$t=6$ で $1-e^{-1} \approx 0.632$ に達する。横軸 $t=6$ で点線が引かれている。 [cite: 31]

--- PAGE 31 ---

回路例 (T型フィルタなど) [cite: 32]
入力 $u_i$, 出力 $u_o$
抵抗 $R$, コンデンサ $C_1, C_2$

$i_R = \frac{u_i - u_o}{R}$
$i_{C1} = C_1 \frac{d}{dt}(u_i - u_o)$ (※図から $u_i$ と $u_o$ の間の電圧は $u_i-u_o$ ではなく、$u_i$ とあるノード電圧の差。仮にそのノード電圧を $u_x$ とすると、$i_{C1} = C_1 \frac{d}{dt}(u_i-u_x)$)
$i_{C2} = C_2 \frac{du_o}{dt}$ [cite: 32]

ノード方程式 (図の回路構成が不明瞭なため、一般的なT型フィルタで想定)
仮に $u_i$ → R → $u_x$ (ノード) → (C1と並列に $u_o$ へ)
                     ↓
                    C2
                     ↓
                    GND
この場合の方程式は複雑になる。

ノートの式:
$\frac{u_i - u_o}{R} = C_1 \frac{d}{dt}(u_i - u_o) + C_2 \frac{du_o}{dt}$ (この式が成立する回路構成は不明) [cite: 32]

ラプラス変換する (初期値0)
$\frac{1}{R}(U_i(s) - U_o(s)) = C_1 s(U_i(s) - U_o(s)) + C_2 s U_o(s)$ [cite: 32]
$(\frac{1}{R} - sC_1)U_i(s) = (\frac{1}{R} - sC_1 - sC_2)U_o(s)$ (※ノートと符号が異なる)

ノートの変形:
$(\frac{1}{R} + sC_1)U_i(s) - (\frac{1}{R} + sC_1 + sC_2)U_o(s) = 0$ (※元の式の右辺が $sC_1 V_0 - sC_1 V_i + sC_2 V_0$ となっている) [cite: 32]
両辺を $U_i(s)$ で割ると (伝達関数 $G(s) = U_o(s)/U_i(s)$)
$(\frac{1}{R} + sC_1) - (\frac{1}{R} + sC_1 + sC_2)G(s) = 0$ [cite: 32]
$G(s) = \frac{\frac{1}{R} + sC_1}{\frac{1}{R} + s(C_1+C_2)} = \frac{1+sRC_1}{1+sR(C_1+C_2)}$ [cite: 32]
