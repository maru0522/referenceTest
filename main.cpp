#include <iostream>
#include <DirectXMath.h>

// Vector4Ç∆çsóÒ4x4ÇÃä|ÇØï˚ÇímÇÈ

struct Vector4
{
    float x, y, z, w;
};

struct Matrix4
{
    Matrix4(void) { Identity(); }
    Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
    {
        m[0][0] = m00;
        m[0][1] = m01;
        m[0][2] = m02;
        m[0][3] = m03;
        m[1][0] = m10;
        m[1][1] = m11;
        m[1][2] = m12;
        m[1][3] = m13;
        m[2][0] = m20;
        m[2][1] = m21;
        m[2][2] = m22;
        m[2][3] = m23;
        m[3][0] = m30;
        m[3][1] = m31;
        m[3][2] = m32;
        m[3][3] = m33;
    }

    float m[4][4];

    void Identity(void)
    {
        m[0][0] = 1;
        m[0][1] = 0;
        m[0][2] = 0;
        m[0][3] = 0;

        m[1][0] = 0;
        m[1][1] = 1;
        m[1][2] = 0;
        m[1][3] = 0;

        m[2][0] = 0;
        m[2][1] = 0;
        m[2][2] = 1;
        m[2][3] = 0;

        m[3][0] = 0;
        m[3][1] = 0;
        m[3][2] = 0;
        m[3][3] = 1;
    }
};

Vector4 Transform(const Matrix4& m, const Vector4& v)
{
    float w = m.m[0][3] * v.x + m.m[1][3] * v.y + m.m[2][3] * v.z + m.m[3][3];
    Vector4 result = {
        m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0] * v.w,
        m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1] * v.w,
        m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2] * v.w,
        m.m[0][3] * v.x + m.m[1][3] * v.y + m.m[2][3] * v.z + m.m[3][3] * v.w,
    };

    result.x /= w;
    result.y /= w;
    result.z /= w;
    result.w /= w;

    return result;

    //const float w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + m.m[3][3];

    //const Vector4 result
    //{
    //    (v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + v.w * m.m[3][0]) / w,
    //    (v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + v.w * m.m[3][1]) / w,
    //    (v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + v.w * m.m[3][2]) / w,
    //    (v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + v.w * m.m[3][3]) / w,
    //};
    //return result;
}

int main()
{
    Vector4 v = { 0,0,0,1 };
    Matrix4 matW = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
       -2,2,0,1
    };

    Matrix4 matV = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,3,1
    };

    Matrix4 matP = {
     0.75,0,0,0,
        0,1,0,0,
        0,0,1,1,
       0,0,-1,0
    };

    Matrix4 matVP = {
     320,   0,0,0,
       0,-240,0,0,
       0,   0,1,0,
     320, 240,0,1
    };

    matV.m[3][2] = 3;
    matP.m[0][0] = 0.75;
    matP.m[3][2] = -1;
    matP.m[2][3] = 1;
    matVP.m[0][0] = 320;
    matVP.m[1][1] = -240;
    matVP.m[3][0] = 320;
    matVP.m[3][1] = 240;

    Vector4 result{};
    std::cout << "result: (" << result.x << ", " << result.y << ", " << result.z << ", " << result.w << ")" << std::endl;
    result = Transform(matW, v);
    std::cout << "result: (" << result.x << ", " << result.y << ", " << result.z << ", " << result.w << ")" << std::endl;
    result = Transform(matV, result);
    std::cout << "result: (" << result.x << ", " << result.y << ", " << result.z << ", " << result.w << ")" << std::endl;
    result = Transform(matP, result);
    std::cout << "result: (" << result.x << ", " << result.y << ", " << result.z << ", " << result.w << ")" << std::endl;
    result = Transform(matVP, result);
    std::cout << "result: (" << result.x << ", " << result.y << ", " << result.z << ", " << result.w << ")" << std::endl;

    std::cout << "end";

    return 0;
}
