////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  EMLL
//  File:     DenseSupervisedExample.cpp (dataset)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DenseSupervisedExample.h"

namespace dataset
{
    DenseSupervisedExample::DenseSupervisedExample(DoubleDataVector instance, double label, double weight) : _dataVector(std::move(instance)), _label(label), _weight(weight)
    {}

    DenseSupervisedExample::DenseSupervisedExample(const SupervisedExample<>& example, uint64_t size) : _dataVector(example.GetDataVector().ToArray(size)), _label(example.GetLabel()), _weight(example.GetWeight())
    {}

    double DenseSupervisedExample::GetWeight() const
    {
        return _weight;
    }

    double DenseSupervisedExample::GetLabel() const
    {
        return _label;
    }

    const DoubleDataVector& DenseSupervisedExample::GetDataVector() const
    {
        return _dataVector;
    }

    void DenseSupervisedExample::Print(std::ostream & os) const
    {
        os << _label << '\t';
        _dataVector.Print(os);
    }

    std::ostream & operator<<(std::ostream & ostream, const DenseSupervisedExample & example)
    {
        example.Print(ostream);
        return ostream;
    }
}
