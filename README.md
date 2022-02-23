# gekkan-io-2022-05-ArduinoIoT-NodeRed
月間I/O 2022年5月号の記事「LINE通知機能付き非接触開閉ボックスをつくってみた」の付録です。


# 用意するもの(物品)
販売リンクは秋月電子通商ですが、Switchscienceなどでも購入可能です。

- ATOM Motion kit 1セット(https://shop.m5stack.com/products/atom-motion-kit-with-motor-and-servo-driver-stm32f0?variant=37875259113644)
- 超音波距離センサ Ultrasonic distance sensor 1台(https://jp.seeedstudio.com/Grove-Ultrasonic-Distance-Sensor.html)
- GeekServo 9G Servo-Gray 1台(https://www.switch-science.com/catalog/6811/)
- Groveケーブル 1本(https://www.switch-science.com/catalog/5214/)
- 折り曲げ式の蓋がついた箱　一つ ([リンク先は箱の一例です](https://www.lotte.co.jp/products/catalogue/choco/03/detail01.html))

# 用意するもの(アカウント)
- Arduino IoT Cloudアカウントと Entryプラン

今回は有料のEntryプランを使用します。**すでに課金プラン(Entry, Maker, Maker Plus)を使っている方は本手順をスキップしてください。
ダウングレードの必要はございません。**

先にこちらでArduinoアカウントを作成してください。
Arduinoアカウントの作成自体は無料で行えます。
https://docs.arduino.cc/

アカウント作成後、先程のarduino.ccのページのメニューバーにあるCloud→IoT Cloudを選択してください。

<img src="https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/image/CloudIoT.png" width="600">

ページ遷移後、ARDUINO IOT CLOUDをクリックしてください。

<img src="https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/image/ArduinoCloudIoT_In.png" width="600">

クリックするとIoT Cloudのページに飛びますので、UPGRADE PLANを選択し、Plan変更ページに移動します。

<img src="https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/image/UPGRADE_PLAN.png" width="600">

**ここから料金が発生します。**　ページ遷移直後はFreeプランが選択されていると思います。ここではEntryプランを使用するため、EntryプランのPURCHASEをクリックします。
ちなみに、プラン名上部にあるMONTHLY/YEARLYのトグルボタンをクリックすると月払い/年払いを指定できます。年払いにすると月払いに
比べて幾分安くなるようです。

<img src="https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/image/Plans.png" width="600">

その後、ページの手順に沿ってクレジットカードで手続きをすすめると、PlanがEntryに変更されます。
もし一通り遊んだあとにEntryプランをやめたい場合には、FreeプランにCHANGE PLANすることで再度無料プランにダウングレードできるかと思います。
現在の自分のプランを確認する際には、再度UPGRADE PLANをクリックしてPlan変更ページに行くと確認できます。

<img src="https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/image/Currentplan.png" width="600">


- enebularアカウント

公式の手順がありますのでこちらを参考に作成してください。

https://blog.enebular.com/enebular/start-enebular-video1/


# インストールするもの
- Arduino Create Plugin

インストーラのダウンロードとインストール手順は下記リンクを参考に行ってください。
また、過去にインストールしたことがある場合はスキップされます。

https://create.arduino.cc/getting-started/plugin/install


# 今回の配線

下記の表と配線図を参考に超音波センサHC-SR04および抵抗付きLEDと結線してください。

Ultrasonic distance sensorはATOM MotionのPORT.Cに結線すればOK。
| ATOM Motion | Ultrasonic distance sensor |
----|---- 
| 5V | Vcc |
| GND | GND |
| G19 | NC |
| G22 | SIG |


GeekServo 9G Servo-GrayはATOM MotionのS1にそのまま結線すればOK。
| ATOM Motion | GeekServo 9G Servo-Gray |
----|---- 
| G | GND |
| V | VCC |
| S1 | PWM |

# ATOM Motionへのプログラム書き込み手順

注意：事前にArduino IoT Cloudで任意のThingsを作成し、事前にATOM liteとデバイスを紐付けておいてください。また、下記手順に進む前にATOM liteとPCをつなげておき、ローカルのArduino IDEなどのシリアルコンソールは事前に終了しておいてください。

1. Variablesをご用意ください。他の設定に関してはデフォルトでOKです。

| 項目名 | 設定値 |
----|---- 
| Name | openFlag |
| Type(ドロップダウンから選択) | boolean |
| Variable Permission | Read & Write |
| Variable Update Policy | On Change |

2. Sketch編集画面から"Open full editor"をクリックします。

<img src="https://github.com/henjin0/gekkan-io-2022-05-ArduinoIoT-NodeRed/blob/main/%E7%94%BB%E5%83%8F%E7%B4%A0%E6%9D%90/ArduinoEditor%E8%B5%B7%E5%8B%95%E6%96%B9%E6%B3%95.png" width="600">

3. 画面が表示されたら、メインのスケッチ(\*.ino)に本githubのmain.inoからコードをコピペします。なお、onOpenFlagChange関数は自動生成された関数名と合わせてください。

4. [ATOM MotionのGithub](https://github.com/m5stack/M5Atom/tree/master/examples/ATOM_BASE/ATOM_Motion)から"AtomMotion.cpp"と"AtomMotion.h"をローカル下にダウンロードします。
5. 下記写真の"Import file into sketch"から4.でダウンロードした２つのファイルをアップロードします。

<img src="https://github.com/henjin0/gekkan-io-2022-05-ArduinoIoT-NodeRed/blob/main/%E7%94%BB%E5%83%8F%E7%B4%A0%E6%9D%90/arduinoeditorimport.png" width="600">

6. [Seeed社のUltrasonic Distance Sensor販売ページ](https://jp.seeedstudio.com/Grove-Ultrasonic-Distance-Sensor.html)のLEARN AND DOCUMENTSからGrove_Ultrasonic Ranger libraryからライブラリファイル(.zip)ダウンロードし展開する。
7. 5.と同じ手順で展開したライブラリファイルの内容をアップロードします。
8. 下図を参考にArduino Editorの書き込み先デバイスからATOM liteを選択し、書き込みボタンをクリックする。

<img src="https://github.com/henjin0/gekkan-io-2022-05-ArduinoIoT-NodeRed/blob/main/%E7%94%BB%E5%83%8F%E7%B4%A0%E6%9D%90/write.png" width="600">

# Node-REDフローについて

Node-RED環境に下記ノードを事前に追加しておいてください。

- node-red-contrib-arduino-iot-cloud
- node-red-contrib-line-messaging-api

今回使用するフローは本リポジトリのflow.jsonにあります。


# License
Please see [LICENSE](https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/LICENSE).
