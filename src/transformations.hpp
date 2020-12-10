#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "vec.hpp"

vec3 translate(const vec3& d, const vec3& p) {
    return p - d;
}

vec3 symX(const vec3& p) {
    vec3 q = p;
    q[0] = abs(p[0]);
    return q;
}

vec3 symXZ(const vec3& p) {
    vec3 q = p;
    q[0] = abs(p[0]);
    q[2] = abs(p[2]);
    return q;
}

vec3 repeatX(float pattern, const vec3& p) {
    return {
        fmodf(p[0] + 0.5f * pattern, pattern) - 0.5f * pattern,
        p[1],
        p[2],
    };
}

vec3 repeatXZ(const vec2& pattern, const vec3& p) {
    return {
        fmodf(p[0] + 0.5f * pattern[0], pattern[0]) - 0.5f * pattern[0],
        p[1],
        fmodf(p[2] + 0.5f * pattern[1], pattern[1]) - 0.5f * pattern[1],
    };
}

vec3 repeatXY(const vec2& pattern, const vec3& p) {
    return {
        fmodf(p[0] + 0.5f * pattern[0], pattern[0]) - 0.5f * pattern[0],
        fmodf(p[1] + 0.5f * pattern[1], pattern[1]) - 0.5f * pattern[1],
        p[2],
    };
}

vec3 repeatLim(float c, float l, const vec3& p) {
    return p-c*vclamp(apply(p/c, roundf),-l,l);
}

float displacement(const vec3& p) {
    return sin(20*p[0])*sin(20*p[1])*sin(20*p[2]);
}

#endif