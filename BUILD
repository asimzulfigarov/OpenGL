cc_library(
    name = "glew",
    hdrs = [
        "Dependencies/GLEW/include/GL/glew.h",
        "Dependencies/GLEW/include/GL/wglew.h",
        "Dependencies/GLEW/include/GL/eglew.h",
        "Dependencies/GLEW/include/GL/glxew.h",
    ],
    includes = ["Dependencies/GLEW/include"],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "glfw",
    hdrs = [
        "Dependencies/GLFW/include/GLFW/glfw3.h",
        "Dependencies/GLFW/include/GLFW/glfw3native.h",
    ],
    includes = ["Dependencies/GLFW/include"],
    visibility = ["//visibility:private"],
)

cc_binary(
    name = "opengl_app",

    srcs = [
        "main.cpp",
        "Renderer.cpp",
        "Shader.cpp",
        "VertexArray.cpp",
        "VertexBuffer.cpp",
        "IndexBuffer.cpp",
        "IndexBuffer.h",
        "Renderer.h",
        "Shader.h",
        "VertexArray.h",
        "VertexBuffer.h",
        "VertexBufferLayout.h",
    ],

    deps = [
        ":glew",
        ":glfw",
    ],

    copts = [
        "-I.",
        "-I./Dependencies/GLEW/include",
        "-I./Dependencies/GLFW/include",
    ],

    linkopts = [
    "opengl32.lib",
    "Dependencies/GLEW/lib/glew32.lib",
    "Dependencies/GLFW/lib/glfw3.lib",
    "user32.lib",
    "gdi32.lib",
    "shell32.lib",
],
)