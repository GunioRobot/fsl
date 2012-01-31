/*  easylog.h - a fairly minimal logging-to-file implementation

    Adrian Groves, FMRIB Image Analysis Group

    Copyright (C) 2007-2008 University of Oxford  */

/*  Part of FSL - FMRIB's Software Library
    http://www.fmrib.ox.ac.uk/fsl
    fsl@fmrib.ox.ac.uk

    Developed at FMRIB (Oxford Centre for Functional Magnetic Resonance
    Imaging of the Brain), Department of Clinical Neurology, Oxford
    University, Oxford, UK


    LICENCE

    FMRIB Software Library, Release 4.0 (c) 2007, The University of
    Oxford (the "Software")

    The Software remains the property of the University of Oxford ("the
    University").

    The Software is distributed "AS IS" under this Licence solely for
    non-commercial use in the hope that it will be useful, but in order
    that the University as a charitable foundation protects its assets for
    the benefit of its educational and research purposes, the University
    makes clear that no condition is made or to be implied, nor is any
    warranty given or to be implied, as to the accuracy of the Software,
    or that it will be suitable for any particular purpose or for use
    under any specific conditions. Furthermore, the University disclaims
    all responsibility for the use which is made of the Software. It
    further disclaims any liability for the outcomes arising from using
    the Software.

    The Licensee agrees to indemnify the University and hold the
    University harmless from and against any and all claims, damages and
    liabilities asserted by third parties (including claims for
    negligence) which arise directly or indirectly from the use of the
    Software or the sale of any products based on the Software.

    No part of the Software may be reproduced, modified, transmitted or
    transferred in any form or by any means, electronic or mechanical,
    without the express permission of the University. The permission of
    the University is not required if the said reproduction, modification,
    transmission or transference is done without financial return, the
    conditions of this Licence are imposed upon the receiver of the
    product, and all original and amended source code is included in any
    transmitted product. You may be held legally responsible for any
    copyright infringement that is caused or encouraged by your failure to
    abide by these terms and conditions.

    You are not permitted under this Licence to use this Software
    commercially. Use for which any financial return is received shall be
    defined as commercial use, and includes (1) integration of all or part
    of the source code or the Software into a product for sale or license
    by or on behalf of Licensee to third parties or (2) use of the
    Software or any derivative of it for research with the final aim of
    developing software products for sale or license to a third party or
    (3) use of the Software or any derivative of it for research with the
    final aim of developing non-software products for sale or license to a
    third party, or (4) use of the Software to provide any service to an
    external organisation for which payment is received. If you are
    interested in using the Software commercially, please contact Isis
    Innovation Limited ("Isis"), the technology transfer company of the
    University, to negotiate a licence. Contact details are:
    innovation@isis.ox.ac.uk quoting reference DE/1112. */

#pragma once

#include "utils/tracer_plus.h"
#include <iostream>
#include <string>
#include "assert.h"

using namespace std;
using namespace Utilities;

#define PRINTNOTE fprintf(stderr, "Note: %s line %d\n", __FILE__, __LINE__);

#define LOG (*EasyLog::CurrentLog())
// Use LOG just like you'd use cout.  (i.e. LOG << your_data << endl;)
// Make sure you call StartLog or StartLogUsingStream before LOGging anything.
// If you want to dump variables directly to this stream, just implement
//    ostream& operator<<(ostream& stream, const your_type& data);

// Changed these to use cout rather than cerr -- since the logfile contains
// almost everything I don't expect people to redirect cout very often.

#define LOG_ERR(x) ((void)((cout<<x),(LOG << x)))
// Use only for things that are safe to duplicate
// LOG_ERR("Note: the matrix " << name << " == " << mat.t() << endl);

#define LOG_ERR_SAFE(x) (cout<<x,EasyLog::LogStarted()?(void)(LOG<<x):(void)0)
// This is safe to use if even if the log might not have started.
// It should only be used in main()'s exception-catching routines

class EasyLog {
 public:
  static ostream* CurrentLog()
    { assert(filestream != NULL); return filestream; }
  static const string& GetOutputDirectory()
    { assert(filestream != NULL); return outDir; }

  static void StartLog(const string& basename);
  static void StartLogUsingStream(ostream& s);
  static void StopLog(bool gzip = false);

  static bool LogStarted()
    { return filestream != NULL; }
  // only use this in situations where the log might not have been started..
  // e.g. in main()'s exception-handling routines

 private:
  static ostream* filestream;
  static string outDir;
};

// Other useful functions:

// Convert almost anything to a string
#include <sstream>
#include <stdexcept>
template<typename type>
inline string stringify(type from)
{
  ostringstream s;
  if (!(s << from))
    throw logic_error("Stringify failed");
  return s.str();
}



// output a vector<int>
#include <vector>
inline ostream& operator<<(ostream& out, vector<int> x)
{
  out << "[ ";
  for (unsigned i = 0; i < x.size(); i++)
    out << x[i] << " ";
  out << "]";
  return out;
}

#include <map>

// A work in progress:
class Warning {
 public:
  static void IssueOnce(const string& text);
  static void IssueAlways(const string& text);
  static void ReissueAll();
 private:
  static map<string, int> issueCount;
};
