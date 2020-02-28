#include "Command.h"

// ここからプログラムの実行が開始される
int main()
{
  // プログラムの初期化処理
  initialize("モンスター・バトル");

  // 勇者の体力
  int hero_hp = 10;

  // モンスターの体力
  int monster_hp = 3;

  // 背景を表示
  set_image(No_0, 400, 300, "bg_paper.jpg");

  // モンスターを表示
  set_image(No_1, 400, 300, "goblin.png");

  printf("モンスターが現れた！");

  // 1秒待つ
  wait(1);

  // 文章を表示
  printf("勇者の攻撃！");

  wait(1);

  printf("モンスターに3のダメージ！");
  monster_hp = monster_hp - 3;

  wait(1);

  // 勝敗を判定する
  if (monster_hp <= 0) {
    printf("モンスターを倒した！");
  }

  // 何かキーが押されるまで待つ
  printf("何かキーを押すと終了します");
  wait_any_key();

  // プログラムの終了処理
  finalize();
}
