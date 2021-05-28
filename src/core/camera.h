#pragma once
#include <eigen/Core>
#include "core/transform.h"
#include "core/film.h"
namespace amber
{
    class Camera
    {
    public:
        Camera(const Transform &CameraToWorld, Film *film) : cameraToWorld(CameraToWorld), film(film)
        {
            
        }
        // float GenerateRay()
        Transform cameraToWorld;
        Film *film;
    };

    class ProjectiveCamera : public Camera
    {
    public:
        ProjectiveCamera(const Transform& cameraToWorld, Film * film) : Camera(cameraToWorld, film){}
        float lensRadius, focalDistance;
    };
}
