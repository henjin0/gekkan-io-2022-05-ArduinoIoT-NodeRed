# gekkan-io-2022-05-ArduinoIoT-NodeRed
月間I/O 2022年5月号の記事「LINE通知機能付き非接触開閉ボックスをつくってみた」の付録です。


# 用意するもの(物品)
販売リンクは秋月電子通商ですが、Switchscienceなどでも購入可能です。

- ATOM Motion kit 1セット(https://shop.m5stack.com/products/atom-motion-kit-with-motor-and-servo-driver-stm32f0?variant=37875259113644)
- 超音波距離センサ Ultrasonic distance sensor 1台(https://jp.seeedstudio.com/Grove-Ultrasonic-Distance-Sensor.html)
- GeekServo 9G Servo-Gray 1台(https://www.switch-science.com/catalog/6811/)
- Groveケーブル 1本(https://www.switch-science.com/catalog/5214/)
- 折り曲げ式の蓋がついた箱　一つ[リンク先は箱の一例です](https://www.lotte.co.jp/products/catalogue/choco/03/detail01.html)

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

# License
Please see [LICENSE](https://github.com/henjin0/gekkan-io-2022-01-ArduinoIoT-NodeRed/blob/main/LICENSE).
