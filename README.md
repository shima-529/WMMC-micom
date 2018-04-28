# WMMC用『マイコン沼に嵌ろう！』資料集
2018年度新入生ゼミに発表させて頂く内容の資料とソースコード配布用のリポジトリです。以下を含んでいます。

- startup.c
    - STM32F303K8Tx 用に書いた、スタートアップルーチンのC言語実装版です。IDE で作成したプロジェクトディレクトリの良い感じのところに置けばいいでしょう。
- Makefile
    - IDEを捨て、コマンドラインでSTM32F3マイコンを開発するための Makefile です。プロジェクトディレクトリを作成し、ルートに置いてください。ソースコードは `src/` 内においてください。リンカスクリプトもルートに置き、`LinkerScript.ld` とすることでビルドが可能になります。
- myStruct.h
    - LPC1114 用に実装した、Renesas社マイコン風のIOレジスタマクロです。
- blink.asm
    - Lチカのアセンブラ版(F303向け)です。以下のコマンドでビルド可能です。

```bash
$ arm-none-eabi-as -mcpu=cortex-m4 -mthumb -o blink.o blink.asm
$ arm-none-eabi-ld -Ttext 0x08000000 -o blink.elf blink.o
```

- hand\_assemble.lst
    - アセンブラを使わず紙と鉛筆によってハンドアセンブルしたLチカプログラムです。F303向けで、生成したバイナリを `arm-none-eabi-objdump` にかけた出力結果となります。
- resume
    - 発表した内容についての補足 PDF です。ディレクトリ内には TeX のソースファイルと完成した pdf ファイルが入っています。

# 引用・転載について
改変の自由等は特に制限しませんが、本リポジトリ内のコードを少しでも引用、改変をし自身の作品に利用された場合は本リポジトリのアドレスを併記してください。
