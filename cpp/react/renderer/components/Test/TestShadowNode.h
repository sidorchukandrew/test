#pragma once

#include "TestMeasurementsManager.h"

#include <react/renderer/components/Test/EventEmitters.h>
#include <react/renderer/components/Test/Props.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>

namespace facebook::react {

extern const char TestComponentName[];

class TestShadowNode final : public ConcreteViewShadowNode<
    TestComponentName,
    TestProps,
    TestEventEmitter> {
 public:
  using ConcreteViewShadowNode::ConcreteViewShadowNode;

  static ShadowNodeTraits BaseTraits() {
    auto traits = ConcreteViewShadowNode::BaseTraits();
    traits.set(ShadowNodeTraits::Trait::LeafYogaNode);
    traits.set(ShadowNodeTraits::Trait::MeasurableYogaNode);
    return traits;
  }

  void setTestMeasurementsManager(
      const std::shared_ptr<TestMeasurementsManager>& manager);

  Size measureContent(
      const LayoutContext& layoutContext,
      const LayoutConstraints& layoutConstraints) const override;

 private:
  std::shared_ptr<TestMeasurementsManager> measurementsManager_;
};

} // namespace facebook::react
