#Decided to separate proton's files here so the main CMakeLists.txt is more readable

set(PROTON_FILES
    
    ${ENGINE_DIR}/PlatformSetup.cpp
    ${ENGINE_DIR}/util/MiscUtils.cpp
    ${ENGINE_DIR}/util/ResourceUtils.cpp
    ${ENGINE_DIR}/util/CRandom.cpp
    ${ENGINE_DIR}/util/MathUtils.cpp
    ${ENGINE_DIR}/util/Variant.cpp
    ${ENGINE_DIR}/Manager/VariantDB.cpp
    ${ENGINE_DIR}/linux/LinuxUtils.cpp
    ${ENGINE_DIR}/ClanLib-2.0/Sources/Core/Math/angle.cpp
    ${ENGINE_DIR}/ClanLib-2.0/Sources/Core/Math/vec2.cpp
    ${ENGINE_DIR}/ClanLib-2.0/Sources/Core/Math/vec3.cpp
    ${ENGINE_DIR}/util/TextScanner.cpp
    ${ENGINE_DIR}/FileSystem/FileSystem.cpp
    ${ENGINE_DIR}/FileSystem/FileManager.cpp
    ${ENGINE_DIR}/FileSystem/StreamingInstance.cpp
    ${ENGINE_DIR}/FileSystem/StreamingInstanceFile.cpp
    ${ENGINE_DIR}/Network/NetSocket.cpp
    ${ENGINE_DIR}/Network/enet/host.c
    ${ENGINE_DIR}/Network/enet/callbacks.c
    ${ENGINE_DIR}/Network/enet/list.c
    ${ENGINE_DIR}/Network/enet/packet.c
    ${ENGINE_DIR}/Network/enet/protocol.c
    ${ENGINE_DIR}/Network/enet/unix.c
    ${ENGINE_DIR}/Network/enet/compress.c
    ${ENGINE_DIR}/Network/enet/peer.c
)