/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef EQUALVALUEBOUNDARYCONSTRAINT_H
#define EQUALVALUEBOUNDARYCONSTRAINT_H

#include "NodalConstraint.h"

class EqualValueBoundaryConstraint;

template<>
InputParameters validParams<EqualValueBoundaryConstraint>();

class EqualValueBoundaryConstraint : public NodalConstraint
{
public:
  EqualValueBoundaryConstraint(const std::string & name, InputParameters parameters);
  virtual ~EqualValueBoundaryConstraint();

protected:

  virtual Real computeQpResidual(Moose::ConstraintType type);
  virtual Real computeQpJacobian(Moose::ConstraintJacobianType type);

  unsigned int _slave_boundary_id;
  Real _penalty;

};

#endif /* EQUALVALUEBOUNDARYCONSTRAINT_H */
