#include "Command.h"

// ここからプログラムの実行が開始される
int main()
{
  // プログラムの初期化処理
  initialize("モンスター・バトル");

  // 背景を表示
  image background;
  background.set(400, 300, "bg_paper.jpg");

  // 文章を表示
  printf("モンスターが現れた！\n");

  // 何かキーが押されるまで待つ
  wait_any_key();

  // 勇者のターン
  printf("勇者の攻撃！\n");
  printf("モンスターを倒した！\n");
  printf("[何かキーを押すと終了します]\n");
  wait_any_key();

  // プログラムの終了処理
  finalize();
}
