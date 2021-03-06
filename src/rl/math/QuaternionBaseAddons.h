//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef _RL_MATH_QUATERNIONBASEADDONS_H_
#define _RL_MATH_QUATERNIONBASEADDONS_H_

void
fromUniform(const Scalar& rand0, const Scalar& rand1, const Scalar& rand2)
{
	eigen_assert(rand0 >= Scalar(0));
	eigen_assert(rand0 <= Scalar(1));
	eigen_assert(rand1 >= Scalar(0));
	eigen_assert(rand1 <= Scalar(1));
	eigen_assert(rand2 >= Scalar(0));
	eigen_assert(rand2 <= Scalar(1));
	
	Scalar sigma1 = ::std::sqrt(Scalar(1) - rand0);
	Scalar sigma2 = ::std::sqrt(rand0);
	Scalar theta1 = Scalar(2) * static_cast< Scalar >(M_PI) * rand1;
	Scalar theta2 = Scalar(2) * static_cast< Scalar >(M_PI) * rand2;
	
	this->w() = ::std::cos(theta2) * sigma2;
	this->x() = ::std::sin(theta1) * sigma1;
	this->y() = ::std::cos(theta1) * sigma1;
	this->z() = ::std::sin(theta2) * sigma2;
}

#endif // _RL_MATH_QUATERNIONBASEADDONS_H_
