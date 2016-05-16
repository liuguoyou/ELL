////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     SupervisedExample.h (dataset)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IDataVector.h"

// stl
#include <cstdint>
#include <memory>
#include <algorithm> // for std::swap

namespace dataset
{
    /// <summary> A supervised example. </summary>
    template<typename DataVectorType>
    class SupervisedExample 
    {
    public:

        SupervisedExample() = default;

        /// <summary> Copy constructor </summary>
        ///
        /// <param name="other"> The other. </param>
        SupervisedExample(const SupervisedExample<DataVectorType>& other);

        SupervisedExample(SupervisedExample<DataVectorType>&& other) = default;
        
        /// <summary> Constructs a supervised example. </summary>
        ///
        /// <param name="instance"> The instance. </param>
        /// <param name="label"> The label. </param>
        /// <param name="weight"> The weight. </param>
        SupervisedExample(std::unique_ptr<DataVectorType> instance, double label, double weight = 1.0);

        /// <summary> Gets the data vector. </summary>
        ///
        /// <returns> The data vector. </returns>
        const DataVectorType& GetDataVector() const { return *_dataVector.get(); }

        /// <summary> Gets the weight. </summary>
        ///
        /// <returns> The weight. </returns>
        double GetWeight() const { return _weight; }

        /// <summary> Gets the label. </summary>
        ///
        /// <returns> The label. </returns>
        double GetLabel() const { return _label; }

        SupervisedExample<DataVectorType>& operator=(SupervisedExample<DataVectorType> other);

        /// <summary> Prints the datavector to an output stream. </summary>
        ///
        /// <param name="os"> [in,out] Stream to write data to. </param>
        void Print(std::ostream& os) const;

    private:
        static void Swap(SupervisedExample<DataVectorType>& a, SupervisedExample<DataVectorType>& b);

        std::unique_ptr<DataVectorType> _dataVector;
        double _label;
        double _weight;
    };

    /// <summary> Stream insertion operator. </summary>
    ///
    /// <param name="ostream"> [in,out] Stream to write data to. </param>
    /// <param name="example"> The example. </param>
    ///
    /// <returns> The shifted ostream. </returns>
    template<typename DataVectorType>
    std::ostream& operator<<(std::ostream& ostream, const SupervisedExample<DataVectorType>& example);

    typedef SupervisedExample<IDataVector> GenericSupervisedExample;
}

#include "../tcc/SupervisedExample.tcc"
