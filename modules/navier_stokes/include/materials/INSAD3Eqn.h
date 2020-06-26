//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "INSADMaterial.h"

/**
 * Computes properties needed for stabilized formulations of the mass, momentum, and energy
 * equations
 */
class INSAD3Eqn : public INSADMaterial
{
public:
  static InputParameters validParams();

  INSAD3Eqn(const InputParameters & parameters);

  void initialSetup() override;

protected:
  void computeQpProperties() override;

  const ADVariableValue & _temperature;
  const ADVariableGradient & _grad_temperature;
  const ADVariableSecond & _second_temperature;
  const ADVariableValue * _temperature_dot;
  const ADMaterialProperty<Real> & _cp;
  const ADMaterialProperty<Real> & _k;
  const ADMaterialProperty<RealVectorValue> * const _grad_k;

  ADMaterialProperty<Real> & _temperature_strong_residual;
  ADMaterialProperty<Real> & _temperature_advective_strong_residual;
  ADMaterialProperty<Real> & _temperature_td_strong_residual;
  ADMaterialProperty<Real> & _temperature_wall_convection_strong_residual;
  ADMaterialProperty<Real> & _temperature_source_strong_residual;

  bool _has_wall_convection;
  Real _wall_convection_alpha;
  Real _wall_temperature;
  bool _has_heat_source;
  const Function * _heat_source_function;
};
