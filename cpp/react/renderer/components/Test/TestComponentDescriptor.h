#pragma once

#include "TestMeasurementsManager.h"
#include "TestShadowNode.h"

#include <react/renderer/core/ConcreteComponentDescriptor.h>

namespace facebook::react {

/*
 * ComponentDescriptor for <Test /> component.
 * Connects the ShadowNode with the rendering system and measurement manager.
 */
class TestComponentDescriptor final
    : public ConcreteComponentDescriptor<TestShadowNode> {
 public:
  TestComponentDescriptor(
      const ComponentDescriptorParameters& parameters)
      : ConcreteComponentDescriptor(parameters),
        measurementsManager_(
            std::make_shared<TestMeasurementsManager>(contextContainer_)) {}

  void adopt(ShadowNode& shadowNode) const override {
    ConcreteComponentDescriptor::adopt(shadowNode);

    auto& TestShadowNode =
        static_cast<TestShadowNode&>(shadowNode);

    TestShadowNode.setTestMeasurementsManager(measurementsManager_);
  }

 private:
  const std::shared_ptr<TestMeasurementsManager> measurementsManager_;
};

} // namespace facebook::react
