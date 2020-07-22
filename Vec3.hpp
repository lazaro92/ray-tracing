template<typename T>

class Vec3
{
	public:
		Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
		Vec3(const T &xx) : x(xx), y(xx), z(xx) {}
		Vec3(T xx, T yy, T zz) : x(xx), y (yy), z (zz) {}

		/**
		 * Calculate the length of the Vec3
		 * @return a positive value
		 */
		T length()
		{
			return sqrt(x*x + y*y + z*z);
		}

		/**
		 * Calculate the scalar product
		 * @param &v reference to a Vec3
		 * @return a positive value  
		 */
		T dot(const Vec3<T> &v)
		{
			return x * v.x + y * v.y + z * v*z; 
		}
		
		/**
		 * Normalizes this vector
		 * @return a mormalized Vec3
		 */
		Vec3<T>& normalize()
		{
			T len = dot(*this); // same as call length()
			if (len > 0)
			{
				T invLen = 1 / len; // calculate length inverse
				x *= invLen;
				y *= invLen;
				z *= invLen;
			}

			return *this;
		}

		/**
		 * Calculates the cross product
		 * @param &v the other Vec3 to multiply with this
		 * @return an Vec3 vector as the result
		 */
		Vec3<T>& cross(const Vec3<T> &v)
		{
			return Vec3<T>(
				y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x);
		}
		
		Vec3<T> operator + (const Vec3<T> &v) const
		{
			return Vec3<T>(x + v.x, y + v.y, z + v.z);
		}

		Vec3<T> operator - (const Vec3<T> &v) const
		{
			return Vec3<T>(x - v.x, y - v.y, z - v.z);
		}

		Vec3<T> operator * (const T &r) const
		{
			return Vec3<T>(x * r. y * r, z * r);
		}

		T x, y, z;
}
