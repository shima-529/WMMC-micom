老害なので、僕のマイコンへの姿勢を振り返ってみる
1. WMMC入会。マイコンとの出会い。えるぴーしー？あーむ？PICとかいうやつと何か関係あるの？
1. マイコンは小難しい。Arduinoの方が楽でいいじゃん。当時はArduinoをマイコンとは思ってなかった。
1. LPCマイコン。Lチカの動作自体はできるけど、ピン設定どうやるの？ってかどこ見ればそれ分かるの？ユーザーマニュアルなる物を手に入れるが何も理解出来ず夏が過ぎる。
1. GPIOの設定はWMMC練習プログラムを見よう見まねで設定でした。この時ピン毎に使える機能が違うことを知った。
1. 続いて先輩が渋い顔をしていたタイマー割り込みの設定。当時はこれだけでも2週間まるまる使った。ペリフェラルへのクロック供給オン、カウントスタートに設定が必要らしい。知るか。
1. 続いてUARTの設定。こちらも先輩のプログラムを見よう見まねで。自分の打ち込んだ文字がターミナルに出た時はとても嬉しかった。データシートの読み方多少わかってきたかも。
1. なんとなーくArduinoに手を出す。なんだこれは。いちいち簡単過ぎるじゃないか。自分のこれまでの苦労を否定されたかのように感じ、怒りと絶望を感じながら遊ぶ。
1. ふと気づく。マイコンはdigitalWriteなる機能の存在を知っているのだろうか。知らないだろう。マイコンはただ値を待ってそれを反映させるだけ。全ては人間の作り物なのだ。しかし、そもそも人口と天然と違いはなんだろうか...もとい、そこに気づいた自分の優位性を悟る。
1. 山の神がRXマイコンを持ち出した。そこで志願して秋月マイコンボード評価用ボードを作成。Elecrowを知る。同時にElecrowガチャを体感する。
1. RXマイコン用のライブラリがあるらしい。でもこれ入れるとコードサイズが驚くほどふくれあがる。こんなもの使ってられるか。優位性を求めてレジスタを手打ちする旅に出た---
1. 苦しい。RXの設定が苦しいのだ。だがここでPDGなぞいけ好かないツールに手を出したくはない。
1. そこからあまり記憶がない。気付いたらいろんなマイコンに手を出していた。夢中だった。確かB2の頃。
1. STM32に出会う。STM32F303K8T6。なんとな〜く買ってみたはいいものの、リファレンスマニュアルをみて驚愕。最高72MHz動作、多機能なタイマーが沢山、DAコンバータ、そしてまさかのオペアンプ付きときた。何、浮動小数の演算器が付いているだと！？全てが驚きだった。そして何よりARMマイコン。ms_waitはLPCのやつをコピペするだけでとりあえずは動く。すごい...
1. ATmega328Pを買った。あのArduinoに載っている石だ。これで憎きArduinoに復讐をしてやる(?)。その後avraでアセンブって全てのペリフェラルを美味しくいただきました。なおC言語で書く場合のヘッダとかは分かりません。
1. 誕生日プレゼントにラズパイを買ってもらった。嬉々として動かしてみたが、所詮ただのミニチュアPC。PythonでIOを制御したものの、楽しくない。シェル芸専用端末になりましたとさ。
1. ついにルネサス(日立?)のレガシーなマイコン、H8とSHに手を出してしまった。調べるとgccを各アーキテクチャ向けにビルドすれば出来るらしい。実際やった。死ぬほど疲れたのでもうやりたくない。
1. mbedが気に入らないので、オレオレmbedを作成。C++のお勉強になりました。
1. C++でオレオレライブラリ作成。理由は従来のマイコンプログラミングに飽きたから。クラスはいいぞ。そしてこの頃、ユーザーマニュアルの読み方が分かった。ブロック図、ペリフェラル動作の説明、レジスタの各ビットの機能。いい感じだ。
1. いつからだろう。英語のマニュアルも難なく読めるようになった。
1. ふと気がつく。当たり前だが、マイコンにはOSが入っていない。だが我々はパソコンのOS上でIDEなる劇重環境を展開させ、そこで開発を行っている。何故だ。何故こんなに装備を固めなくてはならぬのだ。そもそもEclipseのプロジェクト設定はどこをどのようにして設定しているのだ。我々はC言語を書いている。「マイコン語」はこれっぽっちも書いていない。これではいけない。
1. STM32のアセンブリは出来た。割と簡単だったな。専門実験でアセンブリの経験はあるのでスムーズに行けた。ただ気に入らないのが擬似命令やラベルのアドレス展開。これどうやってんの？
1. 「アセンブラは甘え」ということでハンドアセンブルした。とてもつらいがマイコンの気持ちになれたので大満足。
1. コンパイラ(どちらかというとリンカ)の気持ちにもなりたかったので、スタートアップルーチンとリンカスクリプトの勉強をした。
1. なんか知らんが勢いでRXのアセンブリもした。僕は一体どの方向へ進んでいるんだろうか。自分でもそれはわからない。