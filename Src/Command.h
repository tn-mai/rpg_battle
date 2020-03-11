#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

namespace Command {

// 前方宣言.
class ImageNo;

/**
* 文字を表示する.
*
* @param  x      表示開始位置の左端座標.
* @param  y      表示開始位置の下端座標.
* @param  format 文字の書式指定(C言語のprintf関数のものと同じ).
* @param  ...    追加の引数(C言語のprintf関数のものと同じ).
*
* 表示開始位置はウィンドウの左上を原点とし、左右がX軸(右がプラス方向)、上下がY軸(下がプラス方向)の座標系で指定する.
* ウィンドウの大きさは横800ドット、縦600ドットである.
*/
void xyprintf(double x, double y, const char* format, ...);
void printf(const char* format, ...);

/**
* すべての文字を消す.
*/
void clear_text_all();

/**
* 指定した範囲内の文字を消す.
*
* @param  x      消去範囲の左端座標.
* @param  y      消去範囲の下端座標.
* @param  width  消去範囲の横幅.
* @param  height 消去範囲の縦幅.
*
* 範囲内かどうかの判定には、xyprintf関数に設定した座標が使われる.
* また、文字列の一部が範囲外にあったとしても、xyprintfで設定した座標が範囲内にあるなら全て消去される.
*
* 例えばxyprintfを使って、左端座標に右端まで届くような長い文字列を表示したとする.
* 消去範囲を中央から右端までとした場合、この文字列は1文字も消えない.
* 消去範囲を左端から中央までとした場合、この文字列はすべて消える.
*/
void clear_text_area(double x, double y, double width, double height);

/**
* 文字の表示位置の基準となる座標を設定する.
*
* @param x  基準となるX座標.
* @param y  基準となるY座標.
*/
void set_text_base(double x, double y);

/**
* 画像を配置する.
*
* @param  no       画像の管理番号.
* @param  x        表示位置のX座標.
* @param  y        表示位置のY座標.
* @param  filename 画像ファイルの名前.
*
* このプログラムでは、配置した画像ごとに管理番号を付ける.
* 画像の移動や消去は管理番号を通して行う.
*
* 表示位置はウィンドウの左上を原点とし、左右がX軸(右がプラス方向)、上下がY軸(下がプラス方向)の座標系で指定する.
* ウィンドウの大きさは横800ドット、縦600ドットである.
* ここで指定する座標は画像の中心を指す.
*
* noで指定した管理番号に既に別の画像を配置していた場合、
* まずその画像を消去してから、改めてfilenameで指定した画像を配置する.
*/
void set_image(ImageNo no, double x, double y, const char* filename);

/**
* 画像を移動する.
*
* @param  no      画像の管理番号.
* @param  x       移動先のX座標.
* @param  y       移動先のY座標.
* @param  easing  補間方法:
*                   0 等速で移動.
*                   1 加速しながら移動.
*                   2 減速しながら移動.
*                   3 加速しながら移動を始めて、減速しながら停止する.
*                   4 1に似ているが、少し行き過ぎてから戻ってきて停止する.
*                   5 1に似ているが、移動先座標で何度か弾んでから停止する.
* @param  seconds 動作時間(秒).
*
* 位置はウィンドウの左上を原点とし、左右がX軸(右がプラス方向)、上下がY軸(下がプラス方向)の座標系で指定する.
* ウィンドウの大きさは横800ドット、縦600ドットである.
* ここで指定する座標は画像の中心を指す.
*/
void move_image(ImageNo no, double x, double y, int easing, double seconds);

/**
* 画像を拡大・縮小する.
*
* @param  no      画像の管理番号.
* @param  x       拡大・縮小後のX方向の大きさ. マイナス値を設定すると左右が反転する.
* @param  y       拡大・縮小後のY方向の大きさ. マイナス値を設定すると上下が反転する.
* @param  easing  補間方法:
*                   0 等速で拡大・縮小.
*                   1 加速しながら拡大・縮小.
*                   2 減速しながら拡大・縮小.
*                   3 加速しながら拡大・縮小を始めて、減速しながら停止する.
*                   4 1に似ているが、少し拡大・縮小し過ぎてから戻ってきて停止する.
*                   5 1に似ているが、何度か弾むように拡大・縮小しなから停止する.
* @param  seconds 動作時間(秒).
*/
void scale_image(ImageNo no, double x, double y, int easing, double seconds);

/**
* 画像を回転する.
*
* @param  no      画像の管理番号.
* @param  degree  回転させる角度(度数法). マイナス値を設定すると回転方向が逆になる.
* @param  easing  補間方法:
*                   0 等速で回転.
*                   1 加速しながら回転.
*                   2 減速しながら回転.
*                   3 加速しながら回転を始めて、減速しながら停止する.
*                   4 1に似ているが、少し回転し過ぎてから戻ってきて停止する.
*                   5 1に似ているが、何度か弾みなから停止する.
* @param  seconds 動作時間(秒).
*/
void rotate_image(ImageNo no, double degree, int easing, double seconds);

/**
* 画像を傾ける.
*
* @param  no      画像の管理番号.
* @param  scale   傾ける比率. マイナス値を設定すると傾きが逆になる.
* @param  easing  補間方法:
*                   0 等速で傾く.
*                   1 加速しながら傾く.
*                   2 減速しながら傾く.
*                   3 加速しながら傾き始めて、減速しながら停止する.
*                   4 1に似ているが、少し傾き過ぎてから戻ってきて停止する.
*                   5 1に似ているが、何度か弾みなから停止する.
* @param  seconds 動作時間(秒).
*/
void shear_image(ImageNo no, double scale, int easing, double seconds);

/**
* 画像と色を合成する.
*
* @param  no      画像の管理番号.
* @param  red     合成する色の赤成分(0.0～1.0).
* @param  green   合成する色の緑成分(0.0～1.0).
* @param  blue    合成する色の青成分(0.0～1.0).
* @param  alpha   合成する色の透明度(0.0～1.0).
* @param  mod     合成方法:
*                   0 乗算
*                   1 加算
*                   2 減算
* @param  easing  補間方法:
*                   0 等速で色を合成.
*                   1 加速しながら色を合成.
*                   2 減速しながら色を合成.
*                   3 加速しながら合成を始めて、減速しながら停止する.
*                   4 1に似ているが、少し色を出し過ぎてから戻ってきて停止する.
*                   5 1に似ているが、何度か弾むように合成しなから停止する.
* @param  seconds 動作時間(秒).
*/
void color_blend_image(ImageNo no, double red, double green, double blue, double alpha, int mode, int easing, double seconds);

/**
* すべての画像を消す.
*/
void clear_image_all();

/**
* 管理番号で指定された画像を消す.
*
* @param  no 画像の管理番号.
*
* 対象の画像がすでに消されていた場合は何もしない.
*/
void clear_image(ImageNo no);

/**
* 画面をフェードアウトする.
*
* @param  red     フェードアウトフィルターの赤成分(0.0～1.0).
* @param  green   フェードアウトフィルターの緑成分(0.0～1.0).
* @param  blue    フェードアウトフィルターの青成分(0.0～1.0).
* @param  seconds 動作時間(秒).
*/
void fade_out(double red, double green, double blue, double seconds);

/**
* 画面をフェードインする.
*
* @param  seconds 動作時間(秒).
*/
void fade_in(double seconds);

/**
* 一定時間待つ.
*
* @param  seconds 待ち時間(秒).
*/
void sleep(double seconds);

/**
* 一定時間待つ.
*
* @param  usec 待ち時間(マイクロ秒).
*/
void usleep(double usec);

/**
* 何かキーが入力されるまで待つ.
*
* @return 押されたキーに対応する番号.
*/
int wait_any_key();
#define KEYCODE_GAMEPAD 0x1000

/**
* ゲーム操作用のキーが入力されるまで待つ.
*
* @param trigger  false キーが押されていれば入力とみなす.
*                 true  キーが押された瞬間だけを入力とみなす.
*
* @retval  0  上キー
* @retval  1  右キー
* @retval  2  下キー
* @retval  3  左キー
* @retval  4  STARTボタン
* @retval  5  Aボタン
* @retval  6  Bボタン
* @retval  7  Xボタン
* @retval  8  Yボタン
* @retval  9  Lボタン
* @retval 10  Rボタン
*/
int wait_game_key(bool trigger);

/**
* 選択肢を表示して、選択された結果を得る.
*
* @param  x     表示開始位置の左端座標.
* @param  y     表示開始位置の上端座標.
* @param  count 選択肢の数.
* @param  a     ひとつめの選択肢.
* @param  b     ふたつ目の選択肢.
* @param  ...   みっつ以上の選択肢があるなら、カンマで区切って追加していく.
*
* @return 選択された項目の番号.
*         ひとつめの選択肢を0番、ふたつめの選択肢を1番とし、以降は2,3,4のように1ずつ番号が増えていく.
*
* 表示開始位置はウィンドウの左上を原点とし、左右がX軸(右がプラス方向)、上下がY軸(下がプラス方向)の座標系で指定する.
* ウィンドウの大きさは横800ドット、縦600ドットである.
* 選択肢はひとつずつ改行されて下に並ぶので、選択肢を増やす際はウィンドウをはみ出さないように注意すること.
*/
int select(double x, double y, int count, const char* a, const char* b, ...);
int select(int count, const char* a, const char* b, ...);

/**
* 指定した範囲の数値から、選択された値を得る.
*
* @param  x     表示開始位置の左端座標.
* @param  y     表示開始位置の上端座標.
* @param  min   選択範囲の最小値.
* @param  max   選択範囲の最大値.
*
* @return min以上max未満の選択された値.
*
* 表示開始位置はウィンドウの左上を原点とし、左右がX軸(右がプラス方向)、上下がY軸(下がプラス方向)の座標系で指定する.
* ウィンドウの大きさは横800ドット、縦600ドットである.
* 値は上下キーで選択し、決定キー(AボタンorEnterキー)で確定する.
* LまたはRキー(キーボードの場合左Ctrlキーまたは左Shiftキー)を押しながら上下キーを押すと10刻みで選択できる.
*/
int select_number(double x, double y, int min, int max);
int select_number(int min, int max);

/**
* 文字選択パネルを表示し、選択された文字列を得る.
*
* @param  x      表示開始位置の左端座標.
* @param  y      表示開始位置の上端座標.
* @param  max    選択できる文字の数.
* @param  buffer 選択肢た文字を格納するバッファ.
*                格納される文字はSJISの全角文字.
*                全角文字の1文字は2バイト、また最後の文字のあとに終端記号(1バイト)が格納される.
*                このため、バッファの大きさは少なくとも(max * 2 + 1)バイト必要.
*
*/
void select_string(double x, double y, int max, char* buffer);

/**
* 乱数を得る.
*
* @return 0以上2^31-1以下のランダムな値.
*/
int rand();

/**
* アプリケーションを終了する.
*/
void quit();

/**
* 音声を再生する.
*
* @param filename 再生する音声ファイル.
*/
void play_sound(const char* filename);

/**
* 背景音楽を再生する.
*
* @param filename 再生する音声ファイル.
*/
void play_bgm(const char* filename);

/**
* 背景音楽を停止する.
*/
void stop_bgm();

/**
* 音声の音量を設定する.
*
* @param volume 音量
*               0.0 無音
*               1.0 音声データそのままの音量.
*               2.0 音声データの2倍の音量.
*/
void set_sound_volume(double volume);

/**
* 背景音楽の音量を設定する.
*
* @param volume 音量
*               0.0 無音
*               1.0 音声データそのままの音量.
*               2.0 音声データの2倍の音量.
*/
void set_bgm_volume(double volume);

/**
* Commandライブラリを初期化する.
*
* @param title ウィンドウに表示される文章.
*/
void initialize(const char* title);

/**
* Commandライブラリを終了する.
*/
void finalize();

/**
* 色クラス.
*/
class color {
public:
  friend class image;
  color(double r, double g, double b, double a) : r(r), g(g), b(b), a(a) {}
  color(const color&) = delete;
  ~color() = default;
  color& operator=(const color& other) { r = other.r; g = other.g; b = other.b; a = other.a; return *this; }

private:
  double r, g, b, a;
};

extern const color color_red;
extern const color color_green;
extern const color color_blue;
extern const color color_black;
extern const color color_white;
extern const color color_clear;

/**
* 画像制御番号.
*
* @note このクラスを直接使わずにno0～no19マクロを使うこと.
*/
class ImageNo
{
public:
  ImageNo() = delete;
  explicit ImageNo(int n) : no(n) {}
  ~ImageNo() = default;
  ImageNo(const ImageNo& other) : no(other.no) {}
  const ImageNo& operator=(const ImageNo& other) { no = other.no; return *this; }
  operator int() const { return no; }

private:
  int no = 0;
};

/**
* 画像制御クラス.
*/
class image
{
public:
  image() : no(n) { n = (n + 1) % 1024; }
  image(double x, double y, const char* filename) : no(n) {
    n = (n + 1) % 1024;
    set_image(no, x, y, filename);
  }
  image(const image& other) : no(other.no) {}
  ~image() = default;
  const image& operator=(const image& other) { no = other.no; return *this; }

  void move(double x, double y, int easing, double seconds) {
    move_image(no, x, y, easing, seconds);
  }
  void scale(double x, double y, int easing, double seconds) {
    scale_image(no, x, y, easing, seconds);
  }
  void rotate(double degree, int easing, double seconds) {
    rotate_image(no, degree, easing, seconds);
  }
  void shear(double scale, int easing, double seconds) {
    shear_image(no, scale, easing, seconds);
  }
  void color(const color& c, int mode, int easing, double seconds){
    color_blend_image(no, c.r, c.g, c.b, c.a, mode, easing, seconds);
  }
  void clear() { clear_image(no); }
  void set(double x, double y, const char* filename) { set_image(no, x, y, filename); }

private:
  ImageNo no;
  static int n;
};

// 画像制御番号変数のリスト.
extern const ImageNo image_no0;
extern const ImageNo image_no1;
extern const ImageNo image_no2;
extern const ImageNo image_no3;
extern const ImageNo image_no4;
extern const ImageNo image_no5;
extern const ImageNo image_no6;
extern const ImageNo image_no7;
extern const ImageNo image_no8;
extern const ImageNo image_no9;
extern const ImageNo image_no10;
extern const ImageNo image_no11;
extern const ImageNo image_no12;
extern const ImageNo image_no13;
extern const ImageNo image_no14;
extern const ImageNo image_no15;
extern const ImageNo image_no16;
extern const ImageNo image_no17;
extern const ImageNo image_no18;
extern const ImageNo image_no19;

/*
  画像制御番号のリスト.

  初心者向け対策.
  マクロにすると色がつくので見分けやすくなる.
*/
#define No_0 image_no0
#define No_1 image_no1
#define No_2 image_no2
#define No_3 image_no3
#define No_4 image_no4
#define No_5 image_no5
#define No_6 image_no6
#define No_7 image_no7
#define No_8 image_no8
#define No_9 image_no9
#define No_10 image_no10
#define No_11 image_no11
#define No_12 image_no12
#define No_13 image_no13
#define No_14 image_no14
#define No_15 image_no15
#define No_16 image_no16
#define No_17 image_no17
#define No_18 image_no18
#define No_19 image_no19

} // namespace Command

#ifndef USE_COMMAND_NAMESPACE
using namespace Command;
#endif // USE_COMMAND_NAMESPACE

#endif // COMMAND_H_INCLUDED