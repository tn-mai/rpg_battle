/**
* @file UniformBuffer.h
*/
#ifndef UNIFORMBUFFER_H_INCLUDED
#define UNIFORMBUFFER_H_INCLUDED
#include <GL/glew.h>
#include <string>
#include <memory>

class UniformBuffer;
using UniformBufferPtr = std::shared_ptr<UniformBuffer>; ///< UBOポインタ型.

/**
* UBOクラス.
*/
class UniformBuffer {
public:
  static UniformBufferPtr Create(
    GLsizeiptr size, GLuint bindingPoint, const char* name);
  bool BufferSubData(const GLvoid* data, GLintptr offset = 0, GLsizeiptr size = 0);
  void BindBufferRange(GLintptr offset, GLsizeiptr size) const;
  GLsizeiptr Size() const { return size; }
  GLuint BindingPoint() const { return bindingPoint; }
  const std::string& Name() const { return name; }

private:
  UniformBuffer() = default;
  ~UniformBuffer();
  UniformBuffer(const UniformBuffer&) = delete;
  UniformBuffer& operator=(const UniformBuffer&) = delete;

private:
  GLuint ubo = 0; ///< Uniform Buffer Object.
  GLsizeiptr size = 0; ///< UBOのバイトサイズ.
  GLuint bindingPoint = -1; ///< UBOの割り当てて先バインディング・ポイント.
  std::string name; ///< UBO名.
};

#endif // UNIFORMBUFFER_H_INCLUDED