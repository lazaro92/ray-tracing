#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

/**
 * Class that represents a hittable sphere. Inherites form hittable class.
 */
class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3 cen, double r, shared_ptr<material> m)
			: center(cen), radius(r), mat_ptr(m) {};

        virtual bool hit(
            const ray& r, double tmin, double tmax, hit_record& rec) const override;

    public:
        point3 center;
        double radius;
		shared_ptr<material> mat_ptr;
};

/**
 * Calculates the square inside the quadratic equation in order to know if
 * ray hit the sphere
 * @param r - the ray to check if hits the sphere
 * @param t_min - the min t value 
 * @param t_max - the max t value
 * @param hit_record - structure with the information of the hit 
 * @return bool - true if there is a hit, false otherwise.
 */
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant > 0) {
        auto root = sqrt(discriminant);

        auto temp = (-half_b - root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);
			rec.mat_ptr = mat_ptr;
            return true;
        }

        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);
			rec.mat_ptr = mat_ptr;
			return true;
        }
    }

    return false;
}


#endif
