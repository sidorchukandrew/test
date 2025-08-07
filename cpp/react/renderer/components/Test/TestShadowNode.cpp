#include "TestShadowNode.h"

namespace facebook::react {

extern const char TestComponentName[] = "Test";

void TestShadowNode::setTestMeasurementsManager(
    const std::shared_ptr<TestMeasurementsManager>& manager) {
  ensureUnsealed();
  measurementsManager_ = manager;
}

Size TestShadowNode::measureContent(
    const LayoutContext& /*layoutContext*/,
    const LayoutConstraints& layoutConstraints) const {
  return measurementsManager_->measure(getSurfaceId(), layoutConstraints);
}

} // namespace facebook::react
