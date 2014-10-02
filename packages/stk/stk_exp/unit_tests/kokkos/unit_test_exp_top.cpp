// Copyright (c) 2013, Sandia Corporation.
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
// 
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
// 
//     * Neither the name of Sandia Corporation nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 

#include <gtest/gtest.h>

struct Hex8 {
  static const unsigned faces_per_element = 6;
  static const unsigned nodes_per_face = 4;

  inline
  static const unsigned * face_node_ordinals(unsigned face_ordinal)
  {
    static const unsigned m_face_node_ordinals[faces_per_element][nodes_per_face] =
     { { 0, 1, 5, 4 },
       { 1, 2, 6, 5 },
       { 2, 3, 7, 6 },
       { 0, 4, 7, 3 },
       { 0, 3, 2, 1 },
       { 4, 5, 6, 7 } };
  
    return m_face_node_ordinals[face_ordinal];
  }
};

TEST( exp_topology, hex8_face_node_ordinals)
{
  unsigned expected_face_node_ordinals[] = { 1, 2, 6, 5};

  unsigned face_ordinal = 1;

  const unsigned* face_node_ordinals = Hex8::face_node_ordinals(face_ordinal);

  EXPECT_EQ(expected_face_node_ordinals[0], face_node_ordinals[0]);
  EXPECT_EQ(expected_face_node_ordinals[1], face_node_ordinals[1]);
  EXPECT_EQ(expected_face_node_ordinals[2], face_node_ordinals[2]);
  EXPECT_EQ(expected_face_node_ordinals[3], face_node_ordinals[3]);
}
