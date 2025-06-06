Texture2D map : register(t0);
SamplerState samp : register(s0);

// 상수버퍼(constant Buffer)
cbuffer World : register(b0)
{
    matrix world;
}

cbuffer View : register(b1)
{
    matrix view;
}

cbuffer Projection : register(b2)
{
    matrix projection;
}

struct VertexInput
{
    float4 pos : POSITION;
    float2 uv : UV;
};

struct PixelInput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};

// 정점마다 계산실행
PixelInput VS(VertexInput input)
{
    PixelInput result;
    result.pos = input.pos;
    result.pos = mul(result.pos, world);
    result.pos = mul(result.pos, view);
    result.pos = mul(result.pos, projection);
    
    result.uv = input.uv;
    
    return result;
}

// SV : System Value
// TARGET : 그릴 곳
// 픽셀마다 계산실행
float4 PS(PixelInput input) : SV_TARGET
{
    input.uv.x *= 1;
    
    return map.Sample(samp, input.uv);
}