//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADIntegratedBC.h"

class Function;

/**
 * ADPressure applies a pressure on a given boundary in the direction defined by component
 */
template <ComputeStage compute_stage>
class ADPressure : public ADIntegratedBC<compute_stage>
{
public:
  static InputParameters validParams();

  ADPressure(const InputParameters & parameters);

protected:
  ADReal computeQpResidual() override;

  /// displacement component to apply the kernel to
  const int _component;

  ///@{ Pressure value constant factor, function factor, and postprocessor factor
  const Real _constant;
  const Function * const _function;
  const PostprocessorValue * const _postprocessor;
  ///@}

  /// _alpha Parameter for HHT time integration scheme
  const Real _alpha;

  usingIntegratedBCMembers;
};
