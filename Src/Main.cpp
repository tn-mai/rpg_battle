#include "Command.h"

// ��������v���O�����̎��s���J�n�����
int main()
{
  // �v���O�����̏���������
  initialize("�����X�^�[�E�o�g��");

  // �w�i��\��
  image background;
  background.set(400, 300, "bg_paper.jpg");

  // ���͂�\��
  printf("�����X�^�[�����ꂽ�I\n");

  // �����L�[���������܂ő҂�
  wait_any_key();

  // �E�҂̃^�[��
  printf("�E�҂̍U���I\n");
  printf("�����X�^�[��|�����I\n");
  printf("[�����L�[�������ƏI�����܂�]\n");
  wait_any_key();

  // �v���O�����̏I������
  finalize();
}
