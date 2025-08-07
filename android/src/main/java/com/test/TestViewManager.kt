package com.test

import android.graphics.Color
import com.facebook.react.module.annotations.ReactModule
import com.facebook.react.uimanager.SimpleViewManager
import com.facebook.react.uimanager.ThemedReactContext
import com.facebook.react.uimanager.ViewManagerDelegate
import com.facebook.react.uimanager.annotations.ReactProp
import com.facebook.react.viewmanagers.TestViewManagerInterface
import com.facebook.react.viewmanagers.TestViewManagerDelegate

@ReactModule(name = TestViewManager.NAME)
class TestViewManager : SimpleViewManager<TestView>(),
  TestViewManagerInterface<TestView> {
  private val mDelegate: ViewManagerDelegate<TestView>

  init {
    mDelegate = TestViewManagerDelegate(this)
  }

  override fun getDelegate(): ViewManagerDelegate<TestView>? {
    return mDelegate
  }

  override fun getName(): String {
    return NAME
  }

  public override fun createViewInstance(context: ThemedReactContext): TestView {
    return TestView(context)
  }

  @ReactProp(name = "color")
  override fun setColor(view: TestView?, color: String?) {
    view?.setBackgroundColor(Color.parseColor(color))
  }

  companion object {
    const val NAME = "TestView"
  }
}
