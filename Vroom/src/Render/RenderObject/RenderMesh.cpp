#include "Vroom/Render/RenderObject/RenderMesh.h"

namespace vrm
{

RenderMesh::RenderMesh(const MeshData& meshData)
    : m_VertexBuffer(meshData.getRawVericesData(), meshData.getVertexCount() * sizeof(Vertex)),
      m_IndexBuffer(meshData.getRawIndicesData(), meshData.getIndexCount())
{
    m_VertexBufferLayout.pushFloat(3);
    m_VertexBufferLayout.pushFloat(3);
    m_VertexBufferLayout.pushFloat(2);

    m_VertexArray.addBuffer(m_VertexBuffer, m_VertexBufferLayout);
}

RenderMesh::~RenderMesh()
{
}

} // namespace vrm