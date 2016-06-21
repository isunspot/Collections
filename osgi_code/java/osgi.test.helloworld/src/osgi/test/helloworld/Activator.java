package osgi.test.helloworld;

import org.osgi.framework.BundleContext;
import org.osgi.framework.BundleActivator;

public class Activator implements BundleActivator {

	private static BundleContext context;
	HelloWorld demo_rain = null;

	static BundleContext getContext() {
		return context;
	}

	/*
	 * (non-Javadoc)
	 * @see org.osgi.framework.BundleActivator#start(org.osgi.framework.BundleContext)
	 */
	public void start(BundleContext bundleContext) throws Exception {
		Activator.context = bundleContext;

		demo_rain = new HelloWorld(bundleContext);
		new Thread(demo_rain).start();
	}

	/*
	 * (non-Javadoc)
	 * @see org.osgi.framework.BundleActivator#stop(org.osgi.framework.BundleContext)
	 */
	public void stop(BundleContext bundleContext) throws Exception {
		Activator.context = null;
	}

}
