Raspberry pi pico にFreeRTOSを載せるサンプル。LED25　Lチカするだけ

pico-sdkはどこかにダウンロードしておく
pico-sdkのパスを設定する
  export PICO_SDK_PATH=$HOME/pico/pico-sdk
-------------------------------------------------------------------------
git clone -b master https://github.com/kazu025/FreeRtosBlinkSample.git
cd FreeRtosBlinkSample
./mc.sh
./ld.sh

