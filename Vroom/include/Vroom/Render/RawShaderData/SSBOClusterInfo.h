#pragma once

#include <vector>

#include "Vroom/Render/RawShaderData/SSBOCluster.h"

namespace vrm
{

struct SSBOClusterInfo
{
    int xCount = 0;
    int yCount = 0;
    int zCount = 0;
    std::vector<SSBOCluster> clusters;

    int getConstantSize() const
    {
        return sizeof(int) * 3;
    }

    int getVariableSize() const
    {
        return static_cast<int>(sizeof(SSBOCluster) * clusters.size());
    }

    int getSize() const
    {
        return static_cast<int>(sizeof(int) * 3 + sizeof(SSBOCluster) * clusters.size());
    }

    const void* getConstantData() const
    {
        return reinterpret_cast<const void*>(&xCount);
    }

    const void* getVariableData() const
    {
        return reinterpret_cast<const void*>(clusters.data());
    }

    std::vector<std::pair<const void*, size_t>> getData() const
    {
        return { { &xCount, sizeof(int) * 3 }, { clusters.data(), sizeof(SSBOCluster) * clusters.size() } };
    }
};

} // namespace vrm