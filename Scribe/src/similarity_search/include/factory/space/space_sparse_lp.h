/**
 * Non-metric Space Library
 *
 * Authors: Bilegsaikhan Naidan (https://github.com/bileg), Leonid Boytsov (http://boytsov.info).
 * With contributions from Lawrence Cayton (http://lcayton.com/) and others.
 *
 * For the complete list of contributors and further details see:
 * https://github.com/searchivarius/NonMetricSpaceLib 
 * 
 * Copyright (c) 2014
 *
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#ifndef FACTORY_SPACE_SPARSE_LP_H
#define FACTORY_SPACE_SPARSE_LP_H

#include <space/space_sparse_lp.h>

namespace similarity {

/*
 * Creating functions.
 */

template <typename dist_t>
Space<dist_t>* CreateSparseLINF(const AnyParams& /* ignoring params */) {
  // Chebyshev Distance
  return new SpaceSparseLp<dist_t>(-1);
}

template <typename dist_t>
Space<dist_t>* CreateSparseL1(const AnyParams& /* ignoring params */) {
  return new SpaceSparseLp<dist_t>(1);
}

template <typename dist_t>
Space<dist_t>* CreateSparseL2(const AnyParams& /* ignoring params */) {
  return new SpaceSparseLp<dist_t>(2);
}

template <typename dist_t>
Space<dist_t>* CreateSparseL(const AnyParams& AllParams) {
  AnyParamManager pmgr(AllParams);

  dist_t p;

  pmgr.GetParamRequired("p",  p);

  return new SpaceSparseLp<dist_t>(p);
}

/*
 * End of creating functions.
 */

}

#endif
