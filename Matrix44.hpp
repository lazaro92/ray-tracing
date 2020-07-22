template<typename T>
class Matrix44
{
	public:
		Matrix44() {}
		const T* operator [] (uint8_t i) const 
		{
			return m[i];
		}

		T* operator [] (uint8_t i)
		{	
			return m[i];
		}
		
		/**
		 * Multiplies a matrix with this matrix
		 * @param Matrix44 to multiply
		 * @returns Matrix44 as the result 
		 */
		Matrix44 operator * (const Matrix44& rhs) const
		{
			Matrix44 mult;
			
			for (uint_8 i = 0; i < 4; i++) {
				for (uint_8 j = 0; j < 4; j++) {
					mult[i][j] = m[i][0] * rhs[0][j] +
						     m[i][1] * rhs[1][j] +
						     m[i][2] * rhs[2][j] +
						     m[i][3] * rhs[3][j];
				}
			}

			return mult;
		}

		/**
		 * Calculates the transpose matrix of tihs matrix.
		 * @returns Matrix44 transposed
		 */
		Matrix44 transpose() const
	       	{
			Matrix44 transpMat;
			for (uint8_t i = 0; i < 4; ++i) {
				for (uint8_t j = 0; j < 4; ++j) {
					transpMat[i][j] = m[j][i];
				}	
			}	
			return transpMat;		
		}

		T m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
};
