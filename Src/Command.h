#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

namespace Command {

// �O���錾.
class ImageNo;

/**
* ������\������.
*
* @param  x      �\���J�n�ʒu�̍��[���W.
* @param  y      �\���J�n�ʒu�̉��[���W.
* @param  format �����̏����w��(C�����printf�֐��̂��̂Ɠ���).
* @param  ...    �ǉ��̈���(C�����printf�֐��̂��̂Ɠ���).
*
* �\���J�n�ʒu�̓E�B���h�E�̍�������_�Ƃ��A���E��X��(�E���v���X����)�A�㉺��Y��(�����v���X����)�̍��W�n�Ŏw�肷��.
* �E�B���h�E�̑傫���͉�800�h�b�g�A�c600�h�b�g�ł���.
*/
void xyprintf(double x, double y, const char* format, ...);
void printf(const char* format, ...);

/**
* ���ׂĂ̕���������.
*/
void clear_text_all();

/**
* �w�肵���͈͓��̕���������.
*
* @param  x      �����͈͂̍��[���W.
* @param  y      �����͈͂̉��[���W.
* @param  width  �����͈͂̉���.
* @param  height �����͈͂̏c��.
*
* �͈͓����ǂ����̔���ɂ́Axyprintf�֐��ɐݒ肵�����W���g����.
* �܂��A������̈ꕔ���͈͊O�ɂ������Ƃ��Ă��Axyprintf�Őݒ肵�����W���͈͓��ɂ���Ȃ�S�ď��������.
*
* �Ⴆ��xyprintf���g���āA���[���W�ɉE�[�܂œ͂��悤�Ȓ����������\�������Ƃ���.
* �����͈͂𒆉�����E�[�܂łƂ����ꍇ�A���̕������1�����������Ȃ�.
* �����͈͂����[���璆���܂łƂ����ꍇ�A���̕�����͂��ׂď�����.
*/
void clear_text_area(double x, double y, double width, double height);

/**
* �����̕\���ʒu�̊�ƂȂ���W��ݒ肷��.
*
* @param x  ��ƂȂ�X���W.
* @param y  ��ƂȂ�Y���W.
*/
void set_text_base(double x, double y);

/**
* �摜��z�u����.
*
* @param  no       �摜�̊Ǘ��ԍ�.
* @param  x        �\���ʒu��X���W.
* @param  y        �\���ʒu��Y���W.
* @param  filename �摜�t�@�C���̖��O.
*
* ���̃v���O�����ł́A�z�u�����摜���ƂɊǗ��ԍ���t����.
* �摜�̈ړ�������͊Ǘ��ԍ���ʂ��čs��.
*
* �\���ʒu�̓E�B���h�E�̍�������_�Ƃ��A���E��X��(�E���v���X����)�A�㉺��Y��(�����v���X����)�̍��W�n�Ŏw�肷��.
* �E�B���h�E�̑傫���͉�800�h�b�g�A�c600�h�b�g�ł���.
* �����Ŏw�肷����W�͉摜�̒��S���w��.
*
* no�Ŏw�肵���Ǘ��ԍ��Ɋ��ɕʂ̉摜��z�u���Ă����ꍇ�A
* �܂����̉摜���������Ă���A���߂�filename�Ŏw�肵���摜��z�u����.
*/
void set_image(ImageNo no, double x, double y, const char* filename);

/**
* �摜���ړ�����.
*
* @param  no      �摜�̊Ǘ��ԍ�.
* @param  x       �ړ����X���W.
* @param  y       �ړ����Y���W.
* @param  easing  ��ԕ��@:
*                   0 �����ňړ�.
*                   1 �������Ȃ���ړ�.
*                   2 �������Ȃ���ړ�.
*                   3 �������Ȃ���ړ����n�߂āA�������Ȃ����~����.
*                   4 1�Ɏ��Ă��邪�A�����s���߂��Ă���߂��Ă��Ē�~����.
*                   5 1�Ɏ��Ă��邪�A�ړ�����W�ŉ��x���e��ł����~����.
* @param  seconds ���쎞��(�b).
*
* �ʒu�̓E�B���h�E�̍�������_�Ƃ��A���E��X��(�E���v���X����)�A�㉺��Y��(�����v���X����)�̍��W�n�Ŏw�肷��.
* �E�B���h�E�̑傫���͉�800�h�b�g�A�c600�h�b�g�ł���.
* �����Ŏw�肷����W�͉摜�̒��S���w��.
*/
void move_image(ImageNo no, double x, double y, int easing, double seconds);

/**
* �摜���g��E�k������.
*
* @param  no      �摜�̊Ǘ��ԍ�.
* @param  x       �g��E�k�����X�����̑傫��. �}�C�i�X�l��ݒ肷��ƍ��E�����]����.
* @param  y       �g��E�k�����Y�����̑傫��. �}�C�i�X�l��ݒ肷��Ə㉺�����]����.
* @param  easing  ��ԕ��@:
*                   0 �����Ŋg��E�k��.
*                   1 �������Ȃ���g��E�k��.
*                   2 �������Ȃ���g��E�k��.
*                   3 �������Ȃ���g��E�k�����n�߂āA�������Ȃ����~����.
*                   4 1�Ɏ��Ă��邪�A�����g��E�k�����߂��Ă���߂��Ă��Ē�~����.
*                   5 1�Ɏ��Ă��邪�A���x���e�ނ悤�Ɋg��E�k�����Ȃ����~����.
* @param  seconds ���쎞��(�b).
*/
void scale_image(ImageNo no, double x, double y, int easing, double seconds);

/**
* �摜����]����.
*
* @param  no      �摜�̊Ǘ��ԍ�.
* @param  degree  ��]������p�x(�x���@). �}�C�i�X�l��ݒ肷��Ɖ�]�������t�ɂȂ�.
* @param  easing  ��ԕ��@:
*                   0 �����ŉ�].
*                   1 �������Ȃ����].
*                   2 �������Ȃ����].
*                   3 �������Ȃ����]���n�߂āA�������Ȃ����~����.
*                   4 1�Ɏ��Ă��邪�A������]���߂��Ă���߂��Ă��Ē�~����.
*                   5 1�Ɏ��Ă��邪�A���x���e�݂Ȃ����~����.
* @param  seconds ���쎞��(�b).
*/
void rotate_image(ImageNo no, double degree, int easing, double seconds);

/**
* �摜���X����.
*
* @param  no      �摜�̊Ǘ��ԍ�.
* @param  scale   �X����䗦. �}�C�i�X�l��ݒ肷��ƌX�����t�ɂȂ�.
* @param  easing  ��ԕ��@:
*                   0 �����ŌX��.
*                   1 �������Ȃ���X��.
*                   2 �������Ȃ���X��.
*                   3 �������Ȃ���X���n�߂āA�������Ȃ����~����.
*                   4 1�Ɏ��Ă��邪�A�����X���߂��Ă���߂��Ă��Ē�~����.
*                   5 1�Ɏ��Ă��邪�A���x���e�݂Ȃ����~����.
* @param  seconds ���쎞��(�b).
*/
void shear_image(ImageNo no, double scale, int easing, double seconds);

/**
* �摜�ƐF����������.
*
* @param  no      �摜�̊Ǘ��ԍ�.
* @param  red     ��������F�̐Ԑ���(0.0�`1.0).
* @param  green   ��������F�̗ΐ���(0.0�`1.0).
* @param  blue    ��������F�̐���(0.0�`1.0).
* @param  alpha   ��������F�̓����x(0.0�`1.0).
* @param  mod     �������@:
*                   0 ��Z
*                   1 ���Z
*                   2 ���Z
* @param  easing  ��ԕ��@:
*                   0 �����ŐF������.
*                   1 �������Ȃ���F������.
*                   2 �������Ȃ���F������.
*                   3 �������Ȃ��獇�����n�߂āA�������Ȃ����~����.
*                   4 1�Ɏ��Ă��邪�A�����F���o���߂��Ă���߂��Ă��Ē�~����.
*                   5 1�Ɏ��Ă��邪�A���x���e�ނ悤�ɍ������Ȃ����~����.
* @param  seconds ���쎞��(�b).
*/
void color_blend_image(ImageNo no, double red, double green, double blue, double alpha, int mode, int easing, double seconds);

/**
* ���ׂẲ摜������.
*/
void clear_image_all();

/**
* �Ǘ��ԍ��Ŏw�肳�ꂽ�摜������.
*
* @param  no �摜�̊Ǘ��ԍ�.
*
* �Ώۂ̉摜�����łɏ�����Ă����ꍇ�͉������Ȃ�.
*/
void clear_image(ImageNo no);

/**
* ��ʂ��t�F�[�h�A�E�g����.
*
* @param  red     �t�F�[�h�A�E�g�t�B���^�[�̐Ԑ���(0.0�`1.0).
* @param  green   �t�F�[�h�A�E�g�t�B���^�[�̗ΐ���(0.0�`1.0).
* @param  blue    �t�F�[�h�A�E�g�t�B���^�[�̐���(0.0�`1.0).
* @param  seconds ���쎞��(�b).
*/
void fade_out(double red, double green, double blue, double seconds);

/**
* ��ʂ��t�F�[�h�C������.
*
* @param  seconds ���쎞��(�b).
*/
void fade_in(double seconds);

/**
* ��莞�ԑ҂�.
*
* @param  seconds �҂�����(�b).
*/
void sleep(double seconds);

/**
* ��莞�ԑ҂�.
*
* @param  usec �҂�����(�}�C�N���b).
*/
void usleep(double usec);

/**
* �����L�[�����͂����܂ő҂�.
*
* @return �����ꂽ�L�[�ɑΉ�����ԍ�.
*/
int wait_any_key();
#define KEYCODE_GAMEPAD 0x1000

/**
* �Q�[������p�̃L�[�����͂����܂ő҂�.
*
* @param trigger  false �L�[��������Ă���Γ��͂Ƃ݂Ȃ�.
*                 true  �L�[�������ꂽ�u�Ԃ�������͂Ƃ݂Ȃ�.
*
* @retval  0  ��L�[
* @retval  1  �E�L�[
* @retval  2  ���L�[
* @retval  3  ���L�[
* @retval  4  START�{�^��
* @retval  5  A�{�^��
* @retval  6  B�{�^��
* @retval  7  X�{�^��
* @retval  8  Y�{�^��
* @retval  9  L�{�^��
* @retval 10  R�{�^��
*/
int wait_game_key(bool trigger);

/**
* �I������\�����āA�I�����ꂽ���ʂ𓾂�.
*
* @param  x     �\���J�n�ʒu�̍��[���W.
* @param  y     �\���J�n�ʒu�̏�[���W.
* @param  count �I�����̐�.
* @param  a     �ЂƂ߂̑I����.
* @param  b     �ӂ��ڂ̑I����.
* @param  ...   �݂��ȏ�̑I����������Ȃ�A�J���}�ŋ�؂��Ēǉ����Ă���.
*
* @return �I�����ꂽ���ڂ̔ԍ�.
*         �ЂƂ߂̑I������0�ԁA�ӂ��߂̑I������1�ԂƂ��A�ȍ~��2,3,4�̂悤��1���ԍ��������Ă���.
*
* �\���J�n�ʒu�̓E�B���h�E�̍�������_�Ƃ��A���E��X��(�E���v���X����)�A�㉺��Y��(�����v���X����)�̍��W�n�Ŏw�肷��.
* �E�B���h�E�̑傫���͉�800�h�b�g�A�c600�h�b�g�ł���.
* �I�����͂ЂƂ����s����ĉ��ɕ��Ԃ̂ŁA�I�����𑝂₷�ۂ̓E�B���h�E���͂ݏo���Ȃ��悤�ɒ��ӂ��邱��.
*/
int select(double x, double y, int count, const char* a, const char* b, ...);
int select(int count, const char* a, const char* b, ...);

/**
* �w�肵���͈͂̐��l����A�I�����ꂽ�l�𓾂�.
*
* @param  x     �\���J�n�ʒu�̍��[���W.
* @param  y     �\���J�n�ʒu�̏�[���W.
* @param  min   �I��͈͂̍ŏ��l.
* @param  max   �I��͈͂̍ő�l.
*
* @return min�ȏ�max�����̑I�����ꂽ�l.
*
* �\���J�n�ʒu�̓E�B���h�E�̍�������_�Ƃ��A���E��X��(�E���v���X����)�A�㉺��Y��(�����v���X����)�̍��W�n�Ŏw�肷��.
* �E�B���h�E�̑傫���͉�800�h�b�g�A�c600�h�b�g�ł���.
* �l�͏㉺�L�[�őI�����A����L�[(A�{�^��orEnter�L�[)�Ŋm�肷��.
* L�܂���R�L�[(�L�[�{�[�h�̏ꍇ��Ctrl�L�[�܂��͍�Shift�L�[)�������Ȃ���㉺�L�[��������10���݂őI���ł���.
*/
int select_number(double x, double y, int min, int max);
int select_number(int min, int max);

/**
* �����I���p�l����\�����A�I�����ꂽ������𓾂�.
*
* @param  x      �\���J�n�ʒu�̍��[���W.
* @param  y      �\���J�n�ʒu�̏�[���W.
* @param  max    �I���ł��镶���̐�.
* @param  buffer �I�������������i�[����o�b�t�@.
*                �i�[����镶����SJIS�̑S�p����.
*                �S�p������1������2�o�C�g�A�܂��Ō�̕����̂��ƂɏI�[�L��(1�o�C�g)���i�[�����.
*                ���̂��߁A�o�b�t�@�̑傫���͏��Ȃ��Ƃ�(max * 2 + 1)�o�C�g�K�v.
*
*/
void select_string(double x, double y, int max, char* buffer);

/**
* �����𓾂�.
*
* @return 0�ȏ�2^31-1�ȉ��̃����_���Ȓl.
*/
int rand();

/**
* �A�v���P�[�V�������I������.
*/
void quit();

/**
* �������Đ�����.
*
* @param filename �Đ����鉹���t�@�C��.
*/
void play_sound(const char* filename);

/**
* �w�i���y���Đ�����.
*
* @param filename �Đ����鉹���t�@�C��.
*/
void play_bgm(const char* filename);

/**
* �w�i���y���~����.
*/
void stop_bgm();

/**
* �����̉��ʂ�ݒ肷��.
*
* @param volume ����
*               0.0 ����
*               1.0 �����f�[�^���̂܂܂̉���.
*               2.0 �����f�[�^��2�{�̉���.
*/
void set_sound_volume(double volume);

/**
* �w�i���y�̉��ʂ�ݒ肷��.
*
* @param volume ����
*               0.0 ����
*               1.0 �����f�[�^���̂܂܂̉���.
*               2.0 �����f�[�^��2�{�̉���.
*/
void set_bgm_volume(double volume);

/**
* Command���C�u����������������.
*
* @param title �E�B���h�E�ɕ\������镶��.
*/
void initialize(const char* title);

/**
* Command���C�u�������I������.
*/
void finalize();

/**
* �F�N���X.
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
* �摜����ԍ�.
*
* @note ���̃N���X�𒼐ڎg�킸��no0�`no19�}�N�����g������.
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
* �摜����N���X.
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

// �摜����ԍ��ϐ��̃��X�g.
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
  �摜����ԍ��̃��X�g.

  ���S�Ҍ����΍�.
  �}�N���ɂ���ƐF�����̂Ō������₷���Ȃ�.
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