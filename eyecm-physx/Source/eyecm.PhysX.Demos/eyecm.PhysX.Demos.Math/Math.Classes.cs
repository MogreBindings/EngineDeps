using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace eyecm.PhysX.Demos
{
    public struct Vec3
    {
        public float x, y, z;

        public Vec3(float x, float y, float z) { this.x = x; this.y = y; this.z = z; }
        public Vec3(double x, double y, double z) { this.x = (float)x; this.y = (float)y; this.z = (float)z; }

        public static Vec3 operator +(Vec3 a, Vec3 b) { return new Vec3( a.x + b.x, a.y + b.y, a.z + b.z ); }
        public static Vec3 operator -(Vec3 a, Vec3 b) { return new Vec3( a.x - b.x, a.y - b.y, a.z - b.z ); }
        public static Vec3 operator *(Vec3 vec, double v) { return new Vec3( vec.x * v, vec.y * v, vec.z * v ); }
        public static Vec3 operator *(Vec3 vec, float v) { return new Vec3( vec.x * v, vec.y * v, vec.z * v ); }
    }
    public struct Mat33
    {
        public float m11, m12, m13;
        public float m21, m22, m23;
        public float m31, m32, m33;
    }
    public struct Mat44
    {
        public float m11, m21, m31, m41;
        public float m12, m22, m32, m42;
        public float m13, m23, m33, m43;
        public float m14, m24, m34, m44;
        public float[] Values
        {
            get
            {
                return new float[] { 
            m11, m21, m31, m41, 
            m12, m22, m32, m42, 
            m13, m23, m33, m43, 
            m14, m24, m34, m44 };
            }
        }
    }
    public struct Quat
    {
        public float x, y, z, w;

        public Quat(float x, float y, float z, float w) { this.x = x; this.y = y; this.z = z; this.w = w; }
    }
    public struct AABB
    {
        public Vec3 low, high;

        public AABB(Vec3 low, Vec3 high) { this.low = low; this.high = high; }
    }
    public struct OBB
    {
        public Mat33 ori;
        public Vec3 center, dim;

        public OBB(Mat33 ori, Vec3 center, Vec3 dim) { this.ori = ori; this.center = center; this.dim = dim; }
    }
    public struct Line
    {
        public Vec3 origin, dir;

        public Line(Vec3 origin, Vec3 dir) { this.origin = origin; this.dir = dir; }
    }
    public struct Plane
    {
        public Vec3 normal;
        public float d;

        public Plane(Vec3 normal, float d) { this.normal = normal; this.d = d; }
    }
    public struct Capsule
    {
        public Vec3 a, b;
        public float radius;

        public Capsule(Vec3 a, Vec3 b, float radius) { this.a = a; this.b = b; this.radius = radius; }
    }
    public struct Sphere
    {
        public Vec3 center;
        public float radius;

        public Sphere(Vec3 center, float radius) { this.center = center; this.radius = radius; }
    }
    public struct Triangle
    {
        public Vec3 a, b, c;

        public Triangle(Vec3 a, Vec3 b, Vec3 c) { this.a = a; this.b = b; this.c = c; }
    }
}
