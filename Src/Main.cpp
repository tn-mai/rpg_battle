#include "Command.h"

// ��������v���O�����̎��s���J�n�����
int main()
{
  // �v���O�����̏���������
  initialize("�����X�^�[�E�o�g��");

  // �E�҂̗̑�
  int hero_hp = 10;

  // �����X�^�[�̗̑�
  int monster_hp = 3;

  // �w�i��\��
  set_image(No_0, 400, 300, "bg_paper.jpg");

  // �����X�^�[��\��
  set_image(No_1, 400, 300, "goblin.png");

  printf("�����X�^�[�����ꂽ�I");

  // 1�b�҂�
  wait(1);

  // ���͂�\��
  printf("�E�҂̍U���I");

  wait(1);

  printf("�����X�^�[��3�̃_���[�W�I");
  monster_hp = monster_hp - 3;

  wait(1);

  // ���s�𔻒肷��
  if (monster_hp <= 0) {
    printf("�����X�^�[��|�����I");
  }

  // �����L�[���������܂ő҂�
  printf("�����L�[�������ƏI�����܂�");
  wait_any_key();

  // �v���O�����̏I������
  finalize();
}
