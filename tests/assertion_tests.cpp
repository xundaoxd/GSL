///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
// blanket turn off warnings from CppCoreCheck from catch
// so people aren't annoyed by them when running the tool.
#pragma warning(disable : 26440 26426) // from catch
#endif

#if __clang__ || __GNUC__
//disable warnings from gtest
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wundef"
#pragma GCC diagnostic ignored "-Wglobal-constructors"
#pragma GCC diagnostic ignored "-Wused-but-marked-unused"
#pragma GCC diagnostic ignored "-Wcovered-switch-default"
#endif

#include <gtest/gtest.h>

#include <gsl/gsl_assert> // for fail_fast (ptr only), Ensures, Expects

using namespace gsl;

namespace
{
int f(int i)
{
    Expects(i > 0 && i < 10);
    return i;
}

int g(int i)
{
    i++;
    Ensures(i > 0 && i < 10);
    return i;
}
} // namespace

TEST(assertion_tests, expects)
{
    EXPECT_TRUE(f(2) == 2);
    EXPECT_DEATH(f(10), ".*");
}


TEST(assertion_tests, ensures)
{
    EXPECT_TRUE(g(2) == 3);
    EXPECT_DEATH(g(9), ".*");
}

#if __clang__ || __GNUC__
#pragma GCC diagnostic pop
#endif
