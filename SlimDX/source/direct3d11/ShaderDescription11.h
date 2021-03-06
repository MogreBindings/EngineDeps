/*
* Copyright (c) 2007-2010 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#include "Enums11.h"
#include "..\direct3d10\ShaderSignature10.h"

namespace SlimDX
{
	namespace Direct3D11
	{	
		public value class ShaderDescription : System::IEquatable<ShaderDescription>
		{
		private:
			SlimDX::Direct3D10::ShaderSignature^ m_InputSignature;
			bool m_IsInline;
			SlimDX::Direct3D10::ShaderBytecode^ m_Bytecode;
			array<System::String^>^ m_SODecl;
			int m_RasterizedStream;
			int m_NumInputSignatureEntries;
			int m_NumOutputSignatureEntries;
			int m_NumPatchConstantSignatureEntries;

		internal:
			ShaderDescription( const D3DX11_EFFECT_SHADER_DESC& native );
		
		public:
			property SlimDX::Direct3D10::ShaderSignature^ Signature
			{
				SlimDX::Direct3D10::ShaderSignature^ get();
			}
			
			property bool IsInline
			{
				bool get();
			}
			
			property SlimDX::Direct3D10::ShaderBytecode^ Bytecode
			{
				SlimDX::Direct3D10::ShaderBytecode^ get();
			}
			
			property System::String^ StreamOutputDeclaration[int]
			{
				System::String^ get(int index);
			}
			
			property int RasterizedStream
			{
				int get();
			}

			property int InputParameterCount
			{
				int get();
			}
			
			property int OutputParameterCount
			{
				int get();
			}

			property int PatchConstantCount
			{
				int get();
			}

			static bool operator == ( ShaderDescription left, ShaderDescription right );
			static bool operator != ( ShaderDescription left, ShaderDescription right );

			virtual int GetHashCode() override;
			virtual bool Equals( System::Object^ obj ) override;
			virtual bool Equals( ShaderDescription other );
			static bool Equals( ShaderDescription% value1, ShaderDescription% value2 );
		};
	}
};